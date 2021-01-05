#include <utility>

#pragma once

class Camera {
private:
    std::string filename;
    bool _isPhoto;

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

    double redPercent;

    cv::Mat getImage(cv::VideoCapture cap);

    cv::Mat thresholdImg(cv::Mat img);

    cv::Mat getMorphImg(cv::Mat img);

    void setRedPercent(double redPercent);

public:
    void runWithVideoSingleFrame(int* X, int* Y, int* width, int* height);

    bool isBlow();

};