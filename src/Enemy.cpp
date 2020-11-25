#include <iostream>
#include "Enemy.hpp"

void Enemy::enemySetPosition(int baseWidth, int baseHeight )
{
	enemySprite.setPosition(baseWidth / 2, baseHeight * 2 / 3);
}

void Enemy::enemyDraw(){
	window->draw(this->enemySprite);
}

bool Enemy::isCollision(sf::FloatRect gloveBoundingBox, sf::FloatRect fighter1BoundingBox)
{
    return (bool)gloveBoundingBox.intersects(fighter1BoundingBox);
}

sf::Sprite Enemy::getEnemySprite() {
    return enemySprite;
}

void Enemy::lowerHp(){
    this->HP -= 1;
}

int Enemy::getHp() const {
    return HP;
}