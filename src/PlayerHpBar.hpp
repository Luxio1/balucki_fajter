#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.hpp"

class PlayerHpBar {
private:
    int HP = 100;

    sf::Texture hpTexture;
    sf::Sprite hpSprite;

    sf::RenderWindow *window;

    std::string filePath = "C:/Users/pmorl/Desktop/balucki_fajter/Sprites/HP_bar/";

public:
    PlayerHpBar(sf::RenderWindow* window);

    void setPosition(int baseWidth, int baseHeight);

    void resetHealth();

    void draw();

    sf::Sprite getSprite();

    void setHpOnBar(Player* player);

    void setTexture(sf::String filename);

    void setSprite(sf::String filename);
};