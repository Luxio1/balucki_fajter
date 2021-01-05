#include <iostream>
#include "Shield.hpp"

Shield::Shield(sf::RenderWindow* window) {
    shieldTexture.loadFromFile(filePath + "defend_shield-export.png");
    shieldSprite.setTexture(shieldTexture);
    this->window = window;
}

void Shield::setShieldPosition(int X, int Y)
{
    shieldSprite.setPosition(X, Y);
}

void Shield::draw() {
    window->draw(this->shieldSprite);
}


bool Shield::isCollision(sf::FloatRect gloveBoundingBox, sf::FloatRect shieldBoundingBox)
{
    return (bool)gloveBoundingBox.intersects(shieldBoundingBox);
}

sf::FloatRect Shield::getGlobalBounds() {
    return shieldSprite.getGlobalBounds();
}

void Shield::generateShieldPosition(int baseWidth, int baseHeight) {
    int randX = rand() % baseWidth/2;
    int randY = rand() % baseHeight/2;

    this->x = randX;
    this->y = randY;
    setShieldPosition(this->x, this->y);
}