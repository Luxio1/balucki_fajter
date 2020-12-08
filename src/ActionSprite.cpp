#include <iostream>
#include "ActionSprite.h"
#include "Enemy.hpp"

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

