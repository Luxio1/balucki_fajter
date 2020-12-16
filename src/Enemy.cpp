#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(sf::RenderWindow* window) {
    //enemyTexture.loadFromFile(filePath + "/Sprites/Fighters/frajer_fajter1cropped.png");
    //enemySprite.setTexture(enemyTexture);

    //enemySprite.setOrigin(enemyTexture.getSize().x / 2, enemyTexture.getSize().y / 2);
    enemyStanceHighT.loadFromFile(filePath + "frajer_fajter1cropped.png");
    enemyStanceLowT.loadFromFile(filePath + "frajer_fajter2cropped.png");
    enemyStanceHitT.loadFromFile(filePath + "frajer_fajter1_attackedt.png");
    enemyStanceHit2T.loadFromFile(filePath + "frajer_fajter1_attacked2.png");
    enemyStanceAttackT.loadFromFile(filePath + "frajer_fajter_attack_cropped.png");
    enemyStanceSet();
    this->window = window;
}

void Enemy::enemySetPosition(){
    enemySprite.setPosition(enemyPositionX, enemyPositionY);
}

void Enemy::enemySetBasePosition(int baseWidth, int baseHeight ){
    enemyPositionX = baseWidth;
    enemyPositionY = baseHeight * 2 / 3;
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

int Enemy::getRandom() {
    srand (time(NULL));
    isAttack = rand() % 5;
    return isAttack;
}

int Enemy::enemyStance(int time){
    if(time == 5){
        if(enemyTime==0) {
            if(isAttack == 0) enemyAttack();
            else enemyStanceHigh();
            enemyTime=1;
        }
        else {
            if(isAttack == 0) enemyAttack();
            else enemyStanceLow();
            enemyTime=0;
        }
        time = 0;
    }
    else{
        if(enemyTime==0) {
            if(isAttack == 0) enemyAttack();
            else enemyStanceHigh();
        }
        else {
            if(isAttack == 0) enemyAttack();
            else enemyStanceLow();
        }
    }
    return time;
}

void Enemy::enemyStanceHigh(){ enemyTexture = enemyTextureHigh;}

void Enemy::enemyStanceLow(){ enemyTexture = enemyTextureLow; }

void Enemy::enemyAttack(){
    enemyAttackSetSprite();

}

void Enemy::enemyAttackSetSprite(){ enemyTexture = enemyStanceAttackT; }


void Enemy::enemyStance50() {
    enemyStanceHighT.loadFromFile(filePath + "frajer_fajter_damage50%1.png");
    enemyStanceLowT.loadFromFile(filePath + "frajer_fajter_damage50%2.png");
}

void Enemy::enemyStance90() {
    enemyStanceHighT.loadFromFile(filePath + "frajer_fajter_damage90%1.png");
    enemyStanceLowT.loadFromFile(filePath + "frajer_fajter_damage90%2.png");
}

void Enemy::enemyNewPosition(int baseWidth, int baseHeight) {

    int randX = rand() % baseWidth /2 + baseWidth /4;
    enemyPositionX = randX;
    enemySetPosition();
}

void Enemy::enemyStanceHit(){
    enemyTextureHigh = enemyStanceHitT;
    enemyTextureLow = enemyStanceHit2T;
}

void Enemy::enemyStanceSet(){
    enemyTextureHigh = enemyStanceHighT;
    enemyTextureLow = enemyStanceLowT;
}

void Enemy::resetDamage(){
    enemyStanceHighT.loadFromFile(filePath + "frajer_fajter1cropped.png");
    enemyStanceLowT.loadFromFile(filePath + "frajer_fajter2cropped.png");
    HP=100;
}

