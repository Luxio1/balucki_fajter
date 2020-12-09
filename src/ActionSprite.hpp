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
    ActionSprite(sf::RenderWindow *window) {
        //actionTexture.loadFromFile(filePath + "HP_bar.png");
        //dropHpOnBar()

		actionTexture.loadFromFile(filePath + "tys_tys.png");
		actionSprite.setTexture(actionTexture);
		actionSprite.setOrigin(actionTexture.getSize().x / 2, actionTexture.getSize().y / 2);

        //actionSprite.setOrigin(actionTexture.getSize().x / 2, actionTexture.getSize().y / 2);
        this->window = window;
    }

    void actionSpritePosition(int baseWidth, int baseHeight);
    void actionSpriteDraw();

    sf::Sprite getEnemySprite();

    void clearActionSprite();
};

