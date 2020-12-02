/*#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "runWithPhoto.hpp"

using namespace std;
using namespace cv;

Mat runWithPhoto::getThresholdedImage(Mat imgOriginal) {
    Mat imgThresholded, imgThresholded2;

    cv::inRange(imgOriginal, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV),
        imgThresholded);

    cv::inRange(imgOriginal, Scalar(iLowH2, iLowS, iLowV), Scalar(iHighH2, iHighS, iHighV),
        imgThresholded2);

    imgThresholded = imgThresholded | imgThresholded2;

    return imgThresholded;
}

void morphologicalOpenAndClose(Mat* imgThresholded) {
    //morphological opening (removes small objects from the foreground)
    erode(*imgThresholded, *imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    dilate(*imgThresholded, *imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

    //morphological closing (removes small holes from the foreground)
    dilate(*imgThresholded, *imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    erode(*imgThresholded, *imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
}

void runWithPhoto::run() {

    Mat imgTmp;
    imgTmp = imread(filename);
    resize(imgTmp, imgTmp, imgTmp.size() / 5);

    Mat imgLines = Mat::zeros(imgTmp.size(), CV_8UC3);

    while (true) {
        Mat imgOriginal = imread(filename);
        resize(imgOriginal, imgOriginal, imgOriginal.size() / 5);


        if (imgOriginal.empty()) //if not success, break loop
        {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }

        Mat imgHSV;

        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

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

        vector<Mat> channels;
        cv::split(imgThresholded, channels);

        Mat red;
        cv::inRange(channels[0], Scalar(0), Scalar(10), red); // red
// ... do the same for blue, green, etc only changing the Scalar values and the Mat

        double image_size = (double)imgThresholded.cols * (double)imgThresholded.rows;
        double red_percent = (1 - ((double)cv::countNonZero(red)) / image_size) * 100;

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
    }*/