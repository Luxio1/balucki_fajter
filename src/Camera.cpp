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
    resize(img, img, Size(img.cols / 3, img.rows / 3));
    
    return img;
}

Mat Camera::thresholdImg(Mat img) {
    Mat imgThresholded, imgThresholded2;
    cv::inRange(img, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV),
        imgThresholded);
    cv::inRange(img, Scalar(iLowH2, iLowS, iLowV), Scalar(iHighH2, iHighS, iHighV),
        imgThresholded2);

    imgThresholded = imgThresholded | imgThresholded2;
    return imgThresholded;
}

double Camera::getRedPercent(vector<Mat> channels, Mat imgThresholded) {
    Mat red;
    cv::inRange(channels[0], Scalar(0), Scalar(10), red);
    double image_size = (double)imgThresholded.cols * (double)imgThresholded.rows;
    double redPercent = (1 - ((double)cv::countNonZero(red)) / image_size) * 100;
    return redPercent;
}

Mat Camera::getMorphImg(Mat img) {
    erode(img, img, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    dilate(img, img, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

    dilate(img, img, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    erode(img, img, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    return img;
}

void Camera::setNewPosition(int* X, int* Y, int x, int y, Mat imgTransformed) {
    Moments oMoments = moments(imgTransformed);

    double dM01 = oMoments.m01;
    double dM10 = oMoments.m10;
    double dArea = oMoments.m00;

    if (dArea > 10000) {
        int posX = dM10 / dArea;
        int posY = dM01 / dArea;

        x = posX;
        y = posY;
    }

    *X = x;
    *Y = y;
}

Mat Camera::getTransformedImage(Mat inputImage) {
    cvtColor(inputImage, inputImage, COLOR_BGR2HSV);
    Mat imgThresholded = thresholdImg(inputImage);
    Mat imgTransformed = getMorphImg(imgThresholded);
    return imgTransformed;
}





void Camera::runWithVideoSingleFrame(int* X, int* Y, int* width, int* height) {
    VideoCapture static cap(0);

    if (!cap.isOpened())
    {
        cout << "Cannot open the web cam" << endl;
        return;
    }

    Mat inputImage = getImage(cap);

    if (inputImage.empty())
    {
        cout << "Cannot read a frame from video stream" << endl;
        return;
    }

    Mat transformedImage = getTransformedImage(inputImage);

    setNewPosition(X, Y, iLastX, iLastY, transformedImage);

    *width = transformedImage.cols;
    *height = transformedImage.rows;

    vector<Mat> channels;
    cv::split(transformedImage, channels);
    
    double redPercent = getRedPercent(channels, transformedImage);

    setRedPercent(redPercent);

}