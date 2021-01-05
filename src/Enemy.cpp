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
    setStance();
    this->window = window;
}

void Enemy::setPosition(){
    enemySprite.setPosition(enemyPositionX, enemyPositionY);
}

void Enemy::setBasePosition(int baseWidth, int baseHeight ){
    enemyPositionX = baseWidth;
    enemyPositionY = baseHeight * 2 / 3;
}

void Enemy::draw(){
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

void Enemy::decreaseHp(){
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

int Enemy::makeMovableEnemyStance(int time){
    if(time == 5){
        if(enemyTime==0) {
            if(isAttack == 0) attack();
            else setEnemyStanceHigh();
            enemyTime=1;
        }
        else {
            if(isAttack == 0) attack();
            else setEnemyStanceLow();
            enemyTime=0;
        }
        time = 0;
    }
    else{
        if(enemyTime==0) {
            if(isAttack == 0) attack();
            else setEnemyStanceHigh();
        }
        else {
            if(isAttack == 0) attack();
            else setEnemyStanceLow();
        }
    }
    return time;
}

void Enemy::setEnemyStanceHigh(){ enemyTexture = enemyTextureHigh;}

void Enemy::setEnemyStanceLow(){ enemyTexture = enemyTextureLow; }

void Enemy::attack(){
    setAttackSprite();

}

void Enemy::setAttackSprite(){ enemyTexture = enemyStanceAttackT; }


void Enemy::setStance50() {
    enemyStanceHighT.loadFromFile(filePath + "frajer_fajter_damage50%1.png");
    enemyStanceLowT.loadFromFile(filePath + "frajer_fajter_damage50%2.png");
}

void Enemy::setStance90() {
    enemyStanceHighT.loadFromFile(filePath + "frajer_fajter_damage90%1.png");
    enemyStanceLowT.loadFromFile(filePath + "frajer_fajter_damage90%2.png");
}

void Enemy::setNewPostion(int baseWidth, int baseHeight) {

    int randX = rand() % baseWidth /2 + baseWidth /4;
    enemyPositionX = randX;
    setPosition();
}

void Enemy::setHitStance(){
    enemyTextureHigh = enemyStanceHitT;
    enemyTextureLow = enemyStanceHit2T;
}

void Enemy::setStance(){
    enemyTextureHigh = enemyStanceHighT;
    enemyTextureLow = enemyStanceLowT;
}

void Enemy::resetDamage(){
    enemyStanceHighT.loadFromFile(filePath + "frajer_fajter1cropped.png");
    enemyStanceLowT.loadFromFile(filePath + "frajer_fajter2cropped.png");
    HP=100;
}

