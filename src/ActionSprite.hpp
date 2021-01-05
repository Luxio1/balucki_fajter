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

    std::string filePath = "C:/Users/pmorl/Desktop/balucki_fajter/Sprites/Action_sprites/";

public:
    ActionSprite(sf::RenderWindow* window);

    void setSpritePosition(int baseWidth, int baseHeight);
    void drawActionSprite();

    sf::Sprite getEnemySprite();
};

