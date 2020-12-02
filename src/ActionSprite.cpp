#include <iostream>
#include "ActionSprite.h"
#include "Enemy.hpp"

void ActionSprite::actionSpritePosition(int baseWidth, int baseHeight )
{
    actionSprite.setPosition(baseWidth / 3, baseHeight * 1 / 3 );
}

void ActionSprite::actionSpriteDraw(){
    window->draw(this->actionSprite);
}


sf::Sprite ActionSprite::getEnemySprite() {
    return actionSprite;
}

void ActionSprite::setActionSprite(sf::String filename) {
    //setHpTexture(filename);
    actionTexture.loadFromFile(filePath + filename);
    actionSprite.setTexture(actionTexture);
    actionSprite.setOrigin(actionTexture.getSize().x / 2, actionTexture.getSize().y / 2);
    ActionSprite::actionSprite = actionSprite;
}

void ActionSprite::setActionTexture(sf::String filename) {
    actionTexture.loadFromFile(filePath + filename);
}

void ActionSprite::setBlowActionSprite(){
    setActionSprite("tys_tys.png");
}

void ActionSprite::clearActionSprite(){
}

