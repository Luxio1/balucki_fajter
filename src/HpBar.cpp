#include <iostream>
#include "HpBar.h"
#include "Enemy.h"

void HpBar::hpSetPosition(int baseWidth, int baseHeight )
{
    hpSprite.setPosition(baseWidth / 2, baseHeight * 1 / 5 );
}

void HpBar::hpBarDraw(){
    window->draw(this->hpSprite);
}


sf::Sprite HpBar::getEnemySprite() {
    return hpSprite;
}

void HpBar::setHpSprite(sf::String filename) {
    //setHpTexture(filename);
    hpTexture.loadFromFile(filePath + filename);
    hpSprite.setTexture(hpTexture);
    hpSprite.setOrigin(hpTexture.getSize().x / 2, hpTexture.getSize().y / 2);
    HpBar::hpSprite = hpSprite;
}

void HpBar::setHpTexture(sf::String filename) {
    hpTexture.loadFromFile(filePath + filename);
}

void HpBar::dropHpOnBar(Enemy enemy){
    int hp = enemy.getHp();
    //printf("%d", hp);
    if(hp == 100) setHpSprite("HP_bar.png");
    else if(hp<100 && hp>=90) setHpSprite("HP_bar_90%.png");
    else if(hp<90 && hp>=75) setHpSprite("HP_bar_75%.png");
    else if(hp<75 && hp>=50) setHpSprite("HP_bar_50%.png");
    else if(hp<50 && hp>=30) setHpSprite("HP_bar_30%.png");
    else if(hp<30 && hp>=25) setHpSprite("HP_bar_30%.png");
    else if(hp<25 && hp>=15) setHpSprite("HP_bar_25%.png");
    else if(hp<15 ) setHpSprite("HP_bar_5%.png");
    //else if(hp==0) setHpSprite("HP_bar_90%.png");


}




