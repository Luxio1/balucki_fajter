#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Camera.h"

using namespace cv;
using namespace std;

bool isPhoto = true;
string filePath = "/home/luxio/Desktop/balucki_fajter/SamplePhotos/simple/rekawica/test1.jpg";

int main( int argc, char** argv ) {

    //Game Window
    sf::RenderWindow window(sf::VideoMode(1200, 600, 32), "Balucki fajter");

    sf::Texture boxingGloveTexture;
    boxingGloveTexture.loadFromFile("/home/luxio/Desktop/balucki_fajter/Sprites/rekawice/rekawica_lewa.png");
    sf::Sprite glove;
    glove.setTexture(boxingGloveTexture);

    //Photo and camera
//    auto* camera = new Camera(filePath, isPhoto);
//    if(camera->isPhoto()){
//        camera->runWithPhoto();
//    } else {
//        camera->runWithVideo();
//    }


    //Game loop

    sf::Event event{};
    int gloveX = 0;
    int gloveY = 0;

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

        window.clear(sf::Color::Black);
        glove.setPosition(gloveX, gloveY);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            gloveX += -2;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            gloveX += 2;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            gloveY += -2;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            gloveY += 2;
        }
        window.draw(glove);
        window.display();
    }


    return 0;
}