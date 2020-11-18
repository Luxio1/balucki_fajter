#include <utility>

#ifndef BALUCKI_FAJTER_CAMERA_H
#define BALUCKI_FAJTER_CAMERA_H

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

public:
    Camera(std::string path, bool is_photo) {
        this->filename = std::move(path);
        this->_isPhoto = is_photo;
    }

    bool isPhoto() const {
        return _isPhoto;
    };

    void runWithVideo();
    void runWithPhoto();
    void detectRed();
	void runWithVideoSingleFrame(int* X, int* Y, int*, int*);
};

#endif //BALUCKI_FAJTER_CAMERA_H
