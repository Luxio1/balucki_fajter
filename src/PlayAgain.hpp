#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Enemy.hpp"

class PlayAgain {
private:
    sf::Texture playAgainPopUpTexture;
    sf::Sprite playAgainPopUpSprite;

    sf::RenderWindow* window;

    bool play = false;
public:
    bool isPlay() const;

private:
    bool has_player_won;

public:
    PlayAgain(sf::RenderWindow* window);

    void setPosition(int baseWidth, int baseHeight);
    void draw();

    void setSprite();

    void setHasWon(bool has_won);

    void setVictoryTexture();

    void setLostTexture();

    void setStartGame();

    void isGameStart();
};


