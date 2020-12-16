#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Enemy.hpp"

class PlayAgain {
private:


    sf::Texture playAgainPopUpTexture;
    sf::Sprite playAgainPopUpSprite;

    sf::RenderWindow *window;

    std::string filePath = "C:/Users/pmorl/Desktop/Projects/balucki_fajter/Sprites/play_again/";

public:
    PlayAgain(sf::RenderWindow* window);

    void playAgainPopUpSetPosition(int baseWidth, int baseHeight);
    void playAgainPopUpDraw();

    void setPlayAgainSprite();

    void setPlayAgainPopUpTexture();

    void setPlayAgainSetPosition(int baseWidth, int baseHeight);

    void playAgainDraw();
};

