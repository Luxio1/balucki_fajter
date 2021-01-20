#ifndef BALUCKI_FAJTER_GAMELOOP_H
#define BALUCKI_FAJTER_GAMELOOP_H

#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Camera.hpp"
#include "Enemy.hpp"
#include "HpBar.hpp"
#include "Player.hpp"
#include "ActionSprite.hpp"
#include "Background.hpp"
#include "Glove.hpp"
#include "PlayAgain.hpp"
#include "Shield.hpp"


using namespace std;
using namespace cv;

class GameLoop {

private:
    int SLEEP_TIME = 5;
    int INPUT_COUNTDOWN = 4;

    enum playerMode {
        ATTACK_MODE,
        DEFENSE_MODE
    };

    int baseWidth = 1920;
    int baseHeight = 1080;

    sf::RenderWindow *window;



public:
    GameLoop(sf::RenderWindow* window);
    int launch();
    //void playAgain();
};


#endif //BALUCKI_FAJTER_GAMELOOP_H
