#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Camera.h"

using namespace cv;
using namespace std;

bool isPhoto = false;
string filePath = "C:/Users/User/Desktop/balucki_fajter";

// temporary function to test background scaling
void scaleToWindow(sf::RenderWindow* window, sf::Sprite* toScale) {
	float scX = (float)window->getSize().x / toScale->getTexture()->getSize().x;
	float scY = (float)window->getSize().y / toScale->getTexture()->getSize().y;
	toScale->setScale(scX, scY);
}

int main( int argc, char** argv ) {

    //Game Window
	int baseWidth = 1920;
	int baseHeigth = 1080;
    sf::RenderWindow window(sf::VideoMode(baseWidth, baseHeigth, 32), "Balucki fajter");

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
	fighter1.setOrigin(Fighter1Texture.getSize().x / 2, Fighter1Texture.getSize().y / 2);

    //Glove
    sf::Texture boxingGloveTexture;
    boxingGloveTexture.loadFromFile(filePath + "/Sprites/rekawice/rekawica_lewa.png");
    sf::Sprite glove;
    glove.setTexture(boxingGloveTexture);
	glove.setOrigin(boxingGloveTexture.getSize().x / 2, boxingGloveTexture.getSize().y / 2);
	glove.setScale(2, 2);

    //Photo and camera
    auto* camera = new Camera(filePath + "/SamplePhotos/simple/rekawica/test1.jpg", isPhoto);

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
        fighter1.setPosition(baseWidth/2, baseHeigth * 2/3);

		int szer = 0, wys = 0;
		camera->runWithVideoSingleFrame(&gloveX, &gloveY, &szer, &wys);
		gloveX = ((float)gloveX / szer) * baseWidth;
		gloveY = ((float)gloveY / wys) * baseHeigth;

		cout << "window x: " << window.getSize().x << " window y: " << window.getSize().y << endl;
		cout << "x: " << gloveX << " y: " << gloveY << endl;


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