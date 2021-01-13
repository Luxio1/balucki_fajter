#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Shield {
private:
    int x, y;

    sf::Texture shieldTexture;
    sf::Sprite shieldSprite;

    sf::RenderWindow* window;

public:
    Shield(sf::RenderWindow* window);
    void setShieldPosition(int baseWidth, int baseHeight);
    void draw();
    bool isCollision(sf::FloatRect gloveBoundingBox, sf::FloatRect fighter1BoundingBox);
    sf::FloatRect getGlobalBounds();
    void generateShieldPosition(int baseWidth, int baseHeight);
};

