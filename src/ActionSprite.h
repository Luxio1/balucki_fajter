#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Enemy.h"

class ActionSprite {
private:
    //int x, y;
    //bool is_blocking;

    int HP = 100;

    sf::Texture actionTexture;
    sf::Sprite actionSprite;

    sf::RenderWindow *window;

    std::string filePath = "C:/Users/bigel/balucki_fajter/Sprites/Action_sprites/";

public:
    ActionSprite(sf::RenderWindow *window) {
        //actionTexture.loadFromFile(filePath + "HP_bar.png");
        //dropHpOnBar()

        //actionSprite.setOrigin(actionTexture.getSize().x / 2, actionTexture.getSize().y / 2);
        this->window = window;
    }

    void actionSpritePosition(int baseWidth, int baseHeight);
    void actionSpriteDraw();

    sf::Sprite getEnemySprite();

    void setActionTexture(sf::String filename);

    void setActionSprite(sf::String filename);

    void setBlowActionSprite();

    void clearActionSprite();
};

