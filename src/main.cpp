#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Camera.hpp"
#include "Enemy.hpp"
#include "HpBar.hpp"
#include "ActionSprite.h"
#include "Background.h"
#include "Glove.h"

using namespace cv;
using namespace std;

bool isPhoto = false;
string filePath = "C:/Users/User/Desktop/balucki_fajter";

int SLEEP_TIME = 5;
int INPUT_COUNTDOWN = 4;


int main(int argc, char** argv) {

    //Game Window
    int baseWidth = 1920;
    int baseHeight = 1080;
    sf::RenderWindow window(sf::VideoMode(baseWidth, baseHeight, 32), "Balucki fajter");

    //Background
    Background background(&window);
    sf::Sprite backgroundSprite = background.getBackgroundSprites();

    //Enemy
    Enemy enemy(&window);

    //HP bar
    HpBar hpBar(&window);

    //Action Sprite
    ActionSprite actionSprite(&window);

    //Glove
    Glove glove(&window);

    //Photo and camera
    Camera camera(filePath + "/SamplePhotos/simple/rekawica/test1.jpg", isPhoto);

    //Game loop
    sf::Event event{};
    int prevGloveX = 0;
    int prevGloveY = 0;
    int targetGloveX = 0;
    int targetGloveY = 0;
    int gloveX = 0;
    int gloveY = 0;
    int tempGloveV = 7;
    int inputGatherFrame = INPUT_COUNTDOWN;
    int szer = 0, wys = 0;
    int spriteTime=0;

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
        glove.gloveSetPosition(gloveX, gloveY);
        enemy.enemySetPosition(baseWidth, baseHeight);
        hpBar.hpSetPosition(baseWidth, baseHeight);
        actionSprite.clearActionSprite();

        if (--inputGatherFrame == 0) {
            inputGatherFrame = INPUT_COUNTDOWN;
            prevGloveX = gloveX;
            prevGloveY = gloveY;
            camera.runWithVideoSingleFrame(&gloveX, &gloveY, &szer, &wys);
            gloveX = ((float)gloveX / szer) * baseWidth;
            gloveY = ((float)gloveY / wys) * baseHeight;
            targetGloveX = gloveX;
            targetGloveY = gloveY;
        }

        //window.clear(sf::Color::Black);
        glove.gloveSetPosition(gloveX, gloveY);
        enemy.enemySetPosition(baseWidth, baseHeight);
        hpBar.hpSetPosition(baseWidth, baseHeight);
        actionSprite.actionSpritePosition(baseWidth, baseHeight);

        int szer = 0, wys = 0;
        camera.runWithVideoSingleFrame(&gloveX, &gloveY, &szer, &wys);
        gloveX = ((float)gloveX / szer) * baseWidth;
        gloveY = ((float)gloveY / wys) * baseHeight;

        //cout << "window x: " << window.getSize().x << " window y: " << window.getSize().y << endl;
        //cout << "x: " << gloveX << " y: " << gloveY << endl;


        if(enemy.isCollision(glove.gloveGetGlobalBounds(), enemy.getEnemySprite().getGlobalBounds()) && camera.isBlow()){
            printf("-1 \n");
            enemy.setHp();
            actionSprite.setBlowActionSprite();
            spriteTime = 10;
        }



        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
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
        }*/



        window.draw(backgroundSprite);
        enemy.enemyDraw();
        hpBar.dropHpOnBar(enemy);
        hpBar.hpBarDraw();
        if(spriteTime>0) {
            actionSprite.actionSpriteDraw();
            spriteTime--;
        }

        glove.gloveDraw();
        window.display();

        sf::Time sleepTime = sf::milliseconds(SLEEP_TIME);
        sf::sleep(sleepTime);
    }

    return 0;
}
