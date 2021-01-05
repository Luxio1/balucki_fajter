#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Shield {
private:
    int HP = 100;

    sf::Texture shieldTexture;
    sf::Sprite shieldSprite;

    sf::RenderWindow* window;

    std::string filePath = "C:/Users/pmorl/Desktop/balucki_fajter/Sprites/Action_sprites/";

public:
    Shield(sf::RenderWindow* window);

    void shieldPosition(int baseWidth, int baseHeight);
    void shieldDraw();
    bool isCollision(sf::FloatRect gloveBoundingBox, sf::FloatRect fighter1BoundingBox);
    sf::FloatRect Shield::getGlobalBounds();
};

