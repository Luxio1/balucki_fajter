#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Camera.hpp"

using namespace std;
using namespace cv;


void Camera::setRedPercent(double redPercent) {
    this->redPercent = redPercent;
}

bool Camera::isBlow() {
    return (redPercent > 20);
}

Mat Camera::getImage(VideoCapture cap) {
    Mat img;

    cap.read(img);
    flip(img, img, 1);
    imshow("Live preview", img);
    resize(img, img, Size(img.cols / 6, img.rows / 6));
    
    return img;
}

Mat Camera::thresholdImg(Mat img) {
    Mat imgThresholded, imgThresholded2;
    cv::inRange(img, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV),
        imgThresholded); //Threshold the image
    cv::inRange(img, Scalar(iLowH2, iLowS, iLowV), Scalar(iHighH2, iHighS, iHighV),
        imgThresholded2);

    imgThresholded = imgThresholded | imgThresholded2;
    return imgThresholded;
}

Mat Camera::getMorphImg(Mat img) {

    //morphological opening (removes small objects from the foreground)
    erode(img, img, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    dilate(img, img, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

    //morphological closing (removes small holes from the foreground)
    dilate(img, img, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    erode(img, img, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    return img;
}



void Camera::runWithVideoSingleFrame(int* X, int* Y, int* width, int* height) {
    VideoCapture static cap(0); //capture the video from webcam

    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "Cannot open the web cam" << endl;
        return;
    }

    Mat workImg = getImage(cap);
    
    bool bSuccess = !workImg.empty();

    if (!bSuccess) //if not success, break loop
    {
        cout << "Cannot read a frame from video stream" << endl;
        return;
    }

    cvtColor(workImg, workImg, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

    Mat imgThresholded = thresholdImg(workImg);

    imgThresholded = getMorphImg(imgThresholded);

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
    *width = workImg.cols;
    *height = workImg.rows;

    vector<Mat> channels;
    cv::split(imgThresholded, channels);

    Mat red;
    cv::inRange(channels[0], Scalar(0), Scalar(10), red); // red
    double image_size = (double)imgThresholded.cols * (double)imgThresholded.rows;
    double red_percent = (1 - ((double)cv::countNonZero(red)) / image_size) * 100;

    setRedPercent(red_percent);

}