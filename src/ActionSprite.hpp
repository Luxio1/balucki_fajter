#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Enemy.hpp"

class ActionSprite {
private:
    //int x, y;
    //bool is_blocking;

    int HP = 100;

    sf::Texture actionTexture;
    sf::Sprite actionSprite;

    sf::RenderWindow *window;

    std::string filePath = "C:/Users/pmorl/Desktop/Projects/balucki_fajter/Sprites/Action_sprites/";

public:
    ActionSprite(sf::RenderWindow* window);

    void actionSpritePosition(int baseWidth, int baseHeight);
    void actionSpriteDraw();

    sf::Sprite getEnemySprite();

    void clearActionSprite();
};

