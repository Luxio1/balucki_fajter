#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Camera.hpp"
#include "Enemy.hpp"

using namespace cv;
using namespace std;

bool isPhoto = false;
string filePath = "C:/Users/pmorl/Desktop/balucki_fajter";

int SLEEP_TIME = 5;

// temporary function to test background scaling
void scaleToWindow(sf::RenderWindow* window, sf::Sprite* toScale) {
    float scX = (float)window->getSize().x / toScale->getTexture()->getSize().x;
    float scY = (float)window->getSize().y / toScale->getTexture()->getSize().y;
    toScale->setScale(scX, scY);
}

int main(int argc, char** argv) {

    //Game Window
    int baseWidth = 1920;
    int baseHeight = 1080;
    sf::RenderWindow window(sf::VideoMode(baseWidth, baseHeight, 32), "Balucki fajter");

    //Background
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile(filePath + "/Sprites/Backgrounds/Office_scene.png");
    sf::Sprite background;
    background.setTexture(backgroundTexture);
    scaleToWindow(&window, &background);

    //Enemy
    Enemy enemy(&window);

    //Glove
    sf::Texture boxingGloveTexture;
    boxingGloveTexture.loadFromFile(filePath + "/Sprites/rekawice/rekawica_lewa.png");
    sf::Sprite glove;
    glove.setTexture(boxingGloveTexture);
    glove.setOrigin(boxingGloveTexture.getSize().x / 2, boxingGloveTexture.getSize().y / 2);
    glove.setScale(2, 2);

    //Photo and camera
    Camera camera(filePath + "/SamplePhotos/simple/rekawica/test1.jpg", isPhoto);

    //Game loop
    sf::Event event{};
    int gloveX = 0;
    int gloveY = 0;
    int tempGloveV = 7;

    while (window.isOpen()) {
        //Event polling (to event variable)
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                break;
            }
        }

        //window.clear(sf::Color::Black);
        glove.setPosition(gloveX, gloveY);
        enemy.enemySetPosition(baseWidth, baseHeight);

        int szer = 0, wys = 0;
        camera.runWithVideoSingleFrame(&gloveX, &gloveY, &szer, &wys);
        gloveX = ((float)gloveX / szer) * baseWidth;
        gloveY = ((float)gloveY / wys) * baseHeight;
          
        cout << "window x: " << window.getSize().x << " window y: " << window.getSize().y << endl;
        cout << "x: " << gloveX << " y: " << gloveY << endl;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            gloveX += -tempGloveV;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            gloveX += tempGloveV;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            gloveY += -tempGloveV;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            gloveY += tempGloveV;
        }

        window.draw(background);
        enemy.enemyDraw();
        window.draw(glove);
        window.display();

        sf::Time sleepTime = sf::milliseconds(SLEEP_TIME);
        sf::sleep(sleepTime);
    }

    return 0;
}
