#include <string>
using namespace std;
using namespace cv;

#pragma once



class runWithPhoto {
private:
    std::string filename;
    bool _isPhoto;
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

    runWithPhoto(std::string path) {
        this->filename = path;
    }

    Mat runWithPhoto::getThresholdedImage(Mat imgOriginal);
    void morphologicalOpenAndClose(Mat* imgThresholded);
    void runWithPhoto::run();

}