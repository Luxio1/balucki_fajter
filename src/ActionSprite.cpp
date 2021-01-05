#include <iostream>
#include "ActionSprite.hpp"
#include "Enemy.hpp"

ActionSprite::ActionSprite(sf::RenderWindow* window) {
    actionTexture.loadFromFile(filePath + "tys_tys.png");
    actionSprite.setTexture(actionTexture);
    actionSprite.setOrigin(actionTexture.getSize().x / 2, actionTexture.getSize().y / 2);

    this->window = window;
}

void ActionSprite::setPosition(int X, int Y )
{
    actionSprite.setPosition(X,Y);
}

void ActionSprite::draw(){
    window->draw(this->actionSprite);
}


sf::Sprite ActionSprite::getSprite() {
    return actionSprite;
}

