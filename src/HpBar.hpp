#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Enemy.hpp"

class HpBar {
private:
    //int x, y;
    //bool is_blocking;

    int HP = 100;

    sf::Texture hpTexture;
    sf::Sprite hpSprite;

    sf::RenderWindow *window;

    std::string filePath;

public:
    HpBar(sf::RenderWindow* window, std::string filepath) {
        this->filePath = filepath;
        this->window = window;
    }

    void hpSetPosition(int baseWidth, int baseHeight);
    void hpBarDraw();

    sf::Sprite getEnemySprite();

    void dropHpOnBar(Enemy enemy);

    void setHpTexture(sf::String filename);

    void setHpSprite(sf::String filename);
};
