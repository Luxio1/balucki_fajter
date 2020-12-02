#include <utility>

#pragma once

class Camera {
private:
    double redPercent;


public:
    const int iLowH = 170;
    const int iHighH = 180;
    const int iLowH2 = 0;
    const int iHighH2 = 3;

    const int iLowS = 131;
    const int iHighS = 255;

    const int iLowV = 50;
    const int iHighV = 255;

    int iLastX = -1;
    int iLastY = -1;


    Camera() {};

    void morphologicalOpenAndClose(cv::Mat* imgThresholded);
    cv::Mat getThresholdedImage(cv::Mat imgOriginal);

	void runWithVideoSingleFrame(int* X, int* Y, int*, int*);
   

	bool isBlow();

    void setRedPercent(double red_percent);
};