#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Enemy.hpp"

class HpBar {
private:
    sf::Texture hpTexture;
    sf::Sprite hpSprite;

    sf::RenderWindow *window;

public:
    HpBar(sf::RenderWindow* window);

    void setPosition(int baseWidth, int baseHeight);
    void draw();

    sf::Sprite getSprite();

    void setHpOnBar(int hp);

    void setTexture(sf::String filename);

    void resetHealth();

    void setSprite(sf::String filename);
};