#include <iostream>
#include "Enemy.hpp"

void Enemy::enemySetPosition(int baseWidth, int baseHeight )
{
    enemySprite.setPosition(baseWidth, baseHeight * 2 / 3);
    //enemyFaceSprite.setPosition( enemySprite.getPosition().x,  baseHeight - enemySprite.getPosition().y - (enemySprite.getTexture()->getSize().y));
}

void Enemy::enemyDraw(){
    setEnemySprite();
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

void Enemy::setEnemySprite() {
    //setHpTexture(filename);
    //enemyTexture.loadFromFile(filePath + filename);
    enemySprite.setTexture(enemyTexture);
    enemySprite.setOrigin(enemyTexture.getSize().x / 2, enemyTexture.getSize().y / 2);
    Enemy::enemySprite = enemySprite;
}


int Enemy::enemyStance(int time){
    if(time == 5){
        if(enemyTime==0) {
            enemyStanceHigh();
            enemyTime=1;
        }
        else {
            enemyStanceLow();
            enemyTime=0;
        }
        time = 0;
    }
    else{
        if(enemyTime==0) {
            enemyStanceHigh();
        }
        else {
            enemyStanceLow();
        }
    }
    return time;
}

void Enemy::enemyStanceHigh(){ enemyTexture = enemyTextureHigh;}

void Enemy::enemyStanceLow(){ enemyTexture = enemyTextureLow; }


void Enemy::enemyStance50() {
    enemyStanceHighT.loadFromFile(filePath + "frajer_fajter_damage50%1.png");
    enemyStanceLowT.loadFromFile(filePath + "frajer_fajter_damage50%2.png");
}

void Enemy::enemyStance90() {
    enemyStanceHighT.loadFromFile(filePath + "frajer_fajter_damage90%1.png");
    enemyStanceLowT.loadFromFile(filePath + "frajer_fajter_damage90%2.png");
}

void Enemy::enemyNewPosition(int baseWidth, int baseHeight) {

    enemySetPosition(baseWidth/2 + (rand() % (baseWidth-300)+100 - baseWidth/2), baseHeight);
    //enemyStance(3);
}

void Enemy::enemyStanceHit(){
    enemyTextureHigh = enemyStanceHitT;
    enemyTextureLow = enemyStanceHit2T;
}

void Enemy::enemyStanceSet(){
    enemyTextureHigh = enemyStanceHighT;
    enemyTextureLow = enemyStanceLowT;
}

void Enemy::enemyAttackSetSprite(){ enemyTexture = enemyStanceAttackT; }