#include <iostream>
#include "Shield.hpp"

Shield::Shield(sf::RenderWindow* window) {
    shieldTexture.loadFromFile(filePath + "defend_shield-export.png");
    shieldSprite.setTexture(shieldTexture);
    this->window = window;
}

void Shield::shieldPosition(int X, int Y)
{
    shieldSprite.setPosition(X, Y);
}

void Shield::shieldDraw() {
    window->draw(this->shieldSprite);
}


bool Shield::isCollision(sf::FloatRect gloveBoundingBox, sf::FloatRect shieldBoundingBox)
{
    return (bool)gloveBoundingBox.intersects(shieldBoundingBox);
}

sf::FloatRect Shield::getGlobalBounds() {
    return shieldSprite.getGlobalBounds();
}