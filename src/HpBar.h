#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Enemy.h"

class HpBar {
private:
    //int x, y;
    //bool is_blocking;

    int HP = 100;

    sf::Texture hpTexture;
    sf::Sprite hpSprite;

    sf::RenderWindow *window;

    std::string filePath = "C:/Users/bigel/balucki_fajter/Sprites/HP_bar/";

public:
    HpBar(sf::RenderWindow *window) {
        //hpTexture.loadFromFile(filePath + "HP_bar.png");
        //dropHpOnBar()

        //hpSprite.setOrigin(hpTexture.getSize().x / 2, hpTexture.getSize().y / 2);
        this->window = window;
    }

    void hpSetPosition(int baseWidth, int baseHeight);
    void hpBarDraw();

    sf::Sprite getEnemySprite();

    void dropHpOnBar(Enemy enemy);

    void setHpTexture(sf::String filename);

    void setHpSprite(sf::String filename);
};
