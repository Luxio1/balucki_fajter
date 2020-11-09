#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Camera.h"

using namespace cv;
using namespace std;

bool isPhoto = true;
string filePath = "/home/luxio/Desktop/balucki_fajter";

// temporary function to test background scaling
void scaleToWindow(sf::RenderWindow* window, sf::Sprite* toScale) {
	float scX = (float)window->getSize().x / toScale->getTexture()->getSize().x;
	float scY = (float)window->getSize().y / toScale->getTexture()->getSize().y;
	toScale->setScale(scX, scY);
}

int main( int argc, char** argv ) {

    //Game Window
    sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "Balucki fajter");

    //Background
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile(filePath + "/Sprites/Backgrounds/Office_scene.png");
    sf::Sprite background;
    background.setTexture(backgroundTexture);
	scaleToWindow(&window, &background);

    //Fighter
    sf::Texture Fighter1Texture;
    Fighter1Texture.loadFromFile(filePath+"/Sprites/Fighters/frajer_fajter1.png");
    sf::Sprite fighter1;
    fighter1.setTexture(Fighter1Texture);

    //Glove
    sf::Texture boxingGloveTexture;
    boxingGloveTexture.loadFromFile(filePath + "/Sprites/rekawice/rekawica_lewa.png");
    sf::Sprite glove;
    glove.setTexture(boxingGloveTexture);

    //Photo and camera
//    auto* camera = new Camera(filePath + "/SamplePhotos/simple/rekawica/test1.jpg", isPhoto);
//    if(camera->isPhoto()){
//        camera->runWithPhoto();
//    } else {
//        camera->runWithVideo();
//    }


    //Game loop

    sf::Event event{};
    int gloveX = 0;
    int gloveY = 0;
	int tempGloveV = 7;

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

        //window.clear(sf::Color::Black);
        glove.setPosition(gloveX, gloveY);
        fighter1.setPosition(window.getSize().x/2, window.getSize().y/3);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            gloveX += -tempGloveV;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            gloveX += tempGloveV;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            gloveY += -tempGloveV;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            gloveY += tempGloveV;
        }

        window.draw(background);
        window.draw(fighter1);
        window.draw(glove);
        window.display();
        sf::Time sleepTime = sf::milliseconds(5);
		sf::sleep(sleepTime);
    }


    return 0;
}