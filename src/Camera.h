#include <utility>

#ifndef BALUCKI_FAJTER_CAMERA_H
#define BALUCKI_FAJTER_CAMERA_H

class Camera {
    private:
        std::string filename;
        bool is_photo;

    int iLowH = 170;
    int iHighH = 180;
    int iLowH2 = 0;
    int iHighH2 = 3;

    int iLowS = 131;
    int iHighS = 255;

    int iLowV = 50;
    int iHighV = 255;

    int iLastX = -1;
    int iLastY = -1;

public:
        Camera(std::string path, bool is_photo){
            this->filename = std::move(path);
            this->is_photo = is_photo;
        }

        bool isPhoto() const {
            return is_photo;
        };

        void runWithVideo();
        void runWithPhoto();
        void detectRed();
};

#endif //BALUCKI_FAJTER_CAMERA_H
