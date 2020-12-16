#include <iostream>
#include "ActionSprite.hpp"
#include "Enemy.hpp"

ActionSprite::ActionSprite(sf::RenderWindow* window) {
    //actionTexture.loadFromFile(filePath + "HP_bar.png");
    //dropHpOnBar()

    actionTexture.loadFromFile(filePath + "tys_tys.png");
    actionSprite.setTexture(actionTexture);
    actionSprite.setOrigin(actionTexture.getSize().x / 2, actionTexture.getSize().y / 2);

    //actionSprite.setOrigin(actionTexture.getSize().x / 2, actionTexture.getSize().y / 2);
    this->window = window;
}

void ActionSprite::actionSpritePosition(int X, int Y )
{
    actionSprite.setPosition(X,Y);
}

void ActionSprite::actionSpriteDraw(){
    window->draw(this->actionSprite);
}


sf::Sprite ActionSprite::getEnemySprite() {
    return actionSprite;
}

void ActionSprite::clearActionSprite(){
}

