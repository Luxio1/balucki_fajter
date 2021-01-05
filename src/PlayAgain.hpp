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

    std::string filePath = "C:/Users/pmorl/Desktop/balucki_fajter/Sprites/play_again/";

    bool has_player_won;

public:
    PlayAgain(sf::RenderWindow* window);

    void setPosition(int baseWidth, int baseHeight);
    void draw();

    void setSprite();

    void setHasWon(bool has_won);

    void setVictoryTexture();
    
    void setLostTexture();
};

