#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <SFML/Window.hpp>
#include "Camera.h"

using namespace cv;
using namespace std;

bool isPhoto = true;
string filePath = "/home/luxio/Desktop/balucki_fajter/SamplePhotos/simple/rekawica/test1.jpg";
//sf::Window window(sf::VideoMode(800, 600), "Balucki fajter");

int main( int argc, char** argv ) {
    auto* camera = new Camera(filePath, isPhoto);

    if(camera->isPhoto()){
        camera->runWithPhoto();
    } else {
        camera->runWithVideo();
    }

    return 0;
}