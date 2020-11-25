#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Camera.hpp"

using namespace std;
using namespace cv;

void Camera::runWithVideo() {
VideoCapture cap(0); //capture the video from webcam

if (!_isPhoto) {

    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "Cannot open the web cam" << endl;
        return;
    }
}

//Capture a temporary image from the camera
Mat imgTmp;
if (_isPhoto) {
    imgTmp = imread(filename);
    resize(imgTmp, imgTmp, imgTmp.size() / 5);
}
else {
    cap.read(imgTmp);
}

//Create a black image with the size as the camera output
Mat imgLines = Mat::zeros(imgTmp.size(), CV_8UC3);;

while (true) {
    Mat imgOriginal;

    if (_isPhoto) {
        imgOriginal = imread(filename);
        resize(imgOriginal, imgOriginal, imgOriginal.size() / 5);
    }
    else {
        bool bSuccess = cap.read(imgOriginal); // read a new frame from video
    }
    bool bSuccess = !imgOriginal.empty();


    if (!bSuccess) //if not success, break loop
    {
        cout << "Cannot read a frame from video stream" << endl;
        break;
    }

    Mat imgHSV;

    cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

    Mat imgThresholded, imgThresholded2;

    cv::inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV),
        imgThresholded); //Threshold the image
    cv::inRange(imgHSV, Scalar(iLowH2, iLowS, iLowV), Scalar(iHighH2, iHighS, iHighV),
        imgThresholded2);

    imgThresholded = imgThresholded | imgThresholded2;

    //morphological opening (removes small objects from the foreground)
    erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

    //morphological closing (removes small holes from the foreground)
    dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

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

        if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0) {
            //Draw a red line from the previous point to the current point
            line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0, 0, 255), 2);
        }

        iLastX = posX;
        iLastY = posY;
    }

    vector<Mat> channels;
    cv::split(imgThresholded, channels);

    Mat red;
    cv::inRange(channels[0], Scalar(0), Scalar(10), red); // red
// ... do the same for blue, green, etc only changing the Scalar values and the Mat

    double image_size = imgThresholded.cols * imgThresholded.rows;
    double red_percent = (1 - ((double)cv::countNonZero(red)) / image_size) * 100;

    //cout << "Red percent: " << red_percent << "%" << endl;
    if (red_percent > 20) cout << "BANG!!" << endl;

    //to ma dodac aktualna ilosc w % czerwonego na zarejestrowanym obrazie ale trzeba naprawic
    putText(imgThresholded, to_string(red_percent), Point2f(100, 100), FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 255, 255));

    Mat flipHorizontal, flipOriginalHorizontal;
    flip(imgThresholded, flipHorizontal, 1);
    imshow("Thresholded Image", flipHorizontal); //show the thresholded image

    imgOriginal = imgOriginal + imgLines;

    flip(imgOriginal, flipOriginalHorizontal, 1);
    imshow("Original", flipOriginalHorizontal); //show the original image

    int toWait = 30;
    if (_isPhoto) toWait = 300000000;
    if (waitKey(toWait) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
    {
        cout << "esc key is pressed by user" << endl;
        break;
    }
}

}

void Camera::runWithPhoto() {

    Mat imgTmp;
    imgTmp = imread(filename);
    resize(imgTmp, imgTmp, imgTmp.size() / 5);

    Mat imgLines = Mat::zeros(imgTmp.size(), CV_8UC3);

    while (true) {
        Mat imgOriginal;

        imgOriginal = imread(filename);
        resize(imgOriginal, imgOriginal, imgOriginal.size() / 5);

        bool bSuccess = !imgOriginal.empty();


        if (!bSuccess) //if not success, break loop
        {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }

        Mat imgHSV;

        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

        Mat imgThresholded, imgThresholded2;

        cv::inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV),
            imgThresholded); //Threshold the image
        cv::inRange(imgHSV, Scalar(iLowH2, iLowS, iLowV), Scalar(iHighH2, iHighS, iHighV),
            imgThresholded2);

        imgThresholded = imgThresholded | imgThresholded2;

        //morphological opening (removes small objects from the foreground)
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
        dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

        //morphological closing (removes small holes from the foreground)
        dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

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

            if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0) {
                //Draw a red line from the previous point to the current point
                line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0, 0, 255), 2);
            }

            iLastX = posX;
            iLastY = posY;
        }

        vector<Mat> channels;
        cv::split(imgThresholded, channels);

        Mat red;
        cv::inRange(channels[0], Scalar(0), Scalar(10), red); // red
// ... do the same for blue, green, etc only changing the Scalar values and the Mat

        double image_size = imgThresholded.cols * imgThresholded.rows;
        double red_percent = (1 - ((double)cv::countNonZero(red)) / image_size) * 100;

        //cout << "Red percent: " << red_percent << "%" << endl;
        if (red_percent > 20) cout << "BANG!!" << endl;

        //to ma dodac aktualna ilosc w % czerwonego na zarejestrowanym obrazie ale trzeba naprawic
        putText(imgThresholded, to_string(red_percent), Point2f(100, 100), FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 255, 255));

        Mat flipHorizontal, flipOriginalHorizontal;
        flip(imgThresholded, flipHorizontal, 1);
        imshow("Thresholded Image", flipHorizontal); //show the thresholded image

        imgOriginal = imgOriginal + imgLines;

        flip(imgOriginal, flipOriginalHorizontal, 1);
        imshow("Original", flipOriginalHorizontal); //show the original image

        int toWait = 300000000;
        if (waitKey(toWait) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            break;
        }
    }

}

void Camera::setRedPercent(double redPercent) {
    this->redPercent = redPercent;
}

bool Camera::isBlow(){
    return (redPercent > 20);
}

void Camera::runWithVideoSingleFrame(int* X, int* Y, int* szer, int* wys) {
	VideoCapture static cap(0); //capture the video from webcam

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		return;
	}

	//Create a black image with the size as the camera output
	//Mat imgLines = Mat::zeros(imgTmp.size(), CV_8UC3);;

	Mat imgOriginal;
	cap.read(imgOriginal);
	resize(imgOriginal, imgOriginal, Size(imgOriginal.cols/2, imgOriginal.rows/2));
	flip(imgOriginal, imgOriginal, 1);

	
	// cap.read(imgOriginal); // read a new frame from video
	bool bSuccess = !imgOriginal.empty();

	if (!bSuccess) //if not success, break loop
	{
		cout << "Cannot read a frame from video stream" << endl;
		return;
	}

	cvtColor(imgOriginal, imgOriginal, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

	Mat imgThresholded, imgThresholded2;
	cv::inRange(imgOriginal, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV),
		imgThresholded); //Threshold the image
	cv::inRange(imgOriginal, Scalar(iLowH2, iLowS, iLowV), Scalar(iHighH2, iHighS, iHighV),
		imgThresholded2);

	imgThresholded = imgThresholded | imgThresholded2;

	
	//morphological opening (removes small objects from the foreground)
	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
	dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

	//morphological closing (removes small holes from the foreground)
	dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
	

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

		/*
		if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0) {
			//Draw a red line from the previous point to the current point
			line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0, 0, 255), 2);
		}
		*/

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

	double image_size = imgThresholded.cols * imgThresholded.rows;
	double red_percent = (1 - ((double)cv::countNonZero(red)) / image_size) * 100;

	setRedPercent(red_percent);

	//cout << "Red percent: " << red_percent << "%" << endl;
	//if (red_percent > 20) cout << "BANG!!" << endl;
	
	/*
	//to ma dodac aktualna ilosc w % czerwonego na zarejestrowanym obrazie ale trzeba naprawic
	putText(imgThresholded, to_string(red_percent), Point2f(100, 100), FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 255, 255));

	Mat flipHorizontal, flipOriginalHorizontal;
	flip(imgThresholded, flipHorizontal, 1);
	imshow("Thresholded Image", flipHorizontal); //show the thresholded image

	imgOriginal = imgOriginal + imgLines;

	flip(imgOriginal, flipOriginalHorizontal, 1);
	imshow("Original", flipOriginalHorizontal); //show the original image
	*/
}