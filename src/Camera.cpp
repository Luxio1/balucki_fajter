#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Camera.hpp"

using namespace std;
using namespace cv;


Mat getFrame() {
    VideoCapture static cap(0); //capture the video from webcam

    if (!cap.isOpened())
    {
        cout << "Cannot open the web cam" << endl;
        return;
    }

    Mat imgOriginal;

    cap.read(imgOriginal);

    //Create a black image with the size as the camera output
    resize(imgOriginal, imgOriginal, Size(imgOriginal.cols / 2, imgOriginal.rows / 2));
    flip(imgOriginal, imgOriginal, 1);

    return imgOriginal;
}

Mat Camera::getThresholdedImage(Mat imgOriginal) {
    Mat imgThresholded, imgThresholded2;

    cv::inRange(imgOriginal, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV),
        imgThresholded);

    cv::inRange(imgOriginal, Scalar(iLowH2, iLowS, iLowV), Scalar(iHighH2, iHighS, iHighV),
        imgThresholded2);

    imgThresholded = imgThresholded | imgThresholded2;

    return imgThresholded;
}

void Camera::morphologicalOpenAndClose(Mat* imgThresholded) {
    //morphological opening (removes small objects from the foreground)
    erode(*imgThresholded, *imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    dilate(*imgThresholded, *imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

    //morphological closing (removes small holes from the foreground)
    dilate(*imgThresholded, *imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    erode(*imgThresholded, *imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
}

void Camera::setRedPercent(double redPercent) {
    this->redPercent = redPercent;
}

bool Camera::isBlow() {
    return (redPercent > 20);
}

void Camera::runWithVideoSingleFrame(int* X, int* Y, int* szer, int* wys) {

    Mat imgOriginal = getFrame();

	if (imgOriginal.empty()) 
	{
		cout << "Cannot read a frame from video stream" << endl;
		return;
	}

	cvtColor(imgOriginal, imgOriginal, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

    Mat imgThresholded = getThresholdedImage(imgOriginal);

    morphologicalOpenAndClose(&imgThresholded);

	//Calculate the moments of the thresholded image
	Moments oMoments = moments(imgThresholded);

	double dM01 = oMoments.m01;
	double dM10 = oMoments.m10;
	double dArea = oMoments.m00;

	// if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero
	if (dArea > 10000) {
		//calculate the position of the ball
		int posX = dM10 / dArea;
		int posY = dM01 / dArea;

		iLastX = posX;
		iLastY = posY;
	}

	*X = iLastX;
	*Y = iLastY;
	*szer = imgOriginal.cols;
	*wys = imgOriginal.rows;

	vector<Mat> channels;
	cv::split(imgThresholded, channels);

	Mat red;
	cv::inRange(channels[0], Scalar(0), Scalar(10), red); // red
	// ... do the same for blue, green, etc only changing the Scalar values and the Mat

	double imageSize = (double)imgThresholded.cols * (double)imgThresholded.rows;
	double redPercent = (1 - ((double)cv::countNonZero(red)) / imageSize) * 100;

	setRedPercent(redPercent);
}