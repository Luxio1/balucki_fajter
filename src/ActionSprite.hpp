#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Enemy.hpp"

class ActionSprite {
private:
    sf::Texture actionTexture;
    sf::Sprite actionSprite;

    sf::RenderWindow *window;

public:
    ActionSprite(sf::RenderWindow* window);

    void setPosition(int baseWidth, int baseHeight);
    void draw();

    sf::Sprite getSprite();
};

