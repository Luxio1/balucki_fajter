#include <iostream>
#include "Enemy.hpp"

void Enemy::enemySetPosition(int baseWidth, int baseHeight )
{
    enemySprite.setPosition(baseWidth / 2, baseHeight * 2 / 3);
    //enemyFaceSprite.setPosition( enemySprite.getPosition().x,  baseHeight - enemySprite.getPosition().y - (enemySprite.getTexture()->getSize().y));
}

void Enemy::enemyDraw(){
    window->draw(this->enemySprite);
    //window->draw(this->enemyFaceSprite);
}

bool Enemy::isCollision(sf::FloatRect gloveBoundingBox, sf::FloatRect fighter1BoundingBox)
{
    return (bool)gloveBoundingBox.intersects(fighter1BoundingBox);
}

sf::Sprite Enemy::getEnemySprite() {
    return enemySprite;
}

void Enemy::setHp(){
    this->HP -= 1;
}

int Enemy::getHp() const {
    return HP;
}

void Enemy::setHpSprite(sf::String filename) {
    //setHpTexture(filename);
    enemyTexture.loadFromFile(filePath + filename);
    enemySprite.setTexture(enemyTexture);
    enemySprite.setOrigin(enemyTexture.getSize().x / 2, enemyTexture.getSize().y / 2);
    Enemy::enemySprite = enemySprite;
}