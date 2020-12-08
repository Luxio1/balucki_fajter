#include <iostream>
#include "Enemy.hpp"

void Enemy::enemySetPosition(int baseWidth, int baseHeight )
{
    enemySprite.setPosition(baseWidth, baseHeight * 2 / 3);
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

void Enemy::setEnemySprite(sf::String filename) {
    //setHpTexture(filename);
	if (filename == "frajer_fajter1cropped.png")
		enemyTexture = enemyStanceHighT;
	else
		enemyTexture = enemyStanceLowT;
    //enemyTexture.loadFromFile(filePath + filename);
    enemySprite.setTexture(enemyTexture);
    enemySprite.setOrigin(enemyTexture.getSize().x / 2, enemyTexture.getSize().y / 2);
    Enemy::enemySprite = enemySprite;
}

void Enemy::enemyAttackSetSprite(){
    setEnemySprite("frajer_fajter_attack.png");
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

void Enemy::enemyStanceHigh(){ setEnemySprite("frajer_fajter1cropped.png");}

void Enemy::enemyStanceLow(){ setEnemySprite("frajer_fajter2cropped.png"); }

