#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Camera.h"

using namespace cv;
using namespace std;

bool isPhoto = true;
string filePath = "/home/luxio/Desktop/balucki_fajter/SamplePhotos/simple/rekawica/test1.jpg";
//sf::Window window(sf::VideoMode(800, 600), "Balucki fajter");

int main( int argc, char** argv ) {

    //Game Window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Balucki fajter");
    sf::Event event;

    //Game loop
    while(window.isOpen()) {
        //Event polling (to event variable)
        while (window.pollEvent(event)){
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Escape){
                        window.close();
                    }
                    break;
            }
        }
    }

    //Update


    //Render
    window.clear();

    //Draw game
    window.display();

    //Photo and camera
    auto* camera = new Camera(filePath, isPhoto);
    if(camera->isPhoto()){
        camera->runWithPhoto();
    } else {
        camera->runWithVideo();
    }

    return 0;
}