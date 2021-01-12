#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Enemy.hpp"

class EnemyHpBar {
private:
    sf::Texture hpTexture;
    sf::Sprite hpSprite;

    sf::RenderWindow *window;

public:
    EnemyHpBar(sf::RenderWindow* window);

    void setPosition(int baseWidth, int baseHeight);
    void draw();

    sf::Sprite getSprite();

    void setHpOnBar(Enemy* enemy);

    void setTexture(sf::String filename);

    void resetHealth();

    void setSprite(sf::String filename);
};