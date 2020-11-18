#include <iostream>
#include "Enemy.hpp"

void Enemy::enemySetPosition(int baseWidth, int baseHeight )
{
	enemySprite.setPosition(baseWidth / 2, baseHeight * 2 / 3);
}

void Enemy::enemyDraw(){
	window->draw(this->enemySprite);
}