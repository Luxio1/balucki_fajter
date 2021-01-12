#include <iostream>
#include "EnemyHpBar.hpp"
#include "Enemy.hpp"

EnemyHpBar::EnemyHpBar(sf::RenderWindow* window) {
	setSprite("HP_bar.png");
	this->window = window;
}

void EnemyHpBar::resetHealth() {
	setSprite("HP_bar.png");
}

void EnemyHpBar::setPosition(int baseWidth, int baseHeight )
{
    hpSprite.setPosition(baseWidth * 3 / 4, baseHeight * 1 / 5 );
}

void EnemyHpBar::draw(){
    window->draw(this->hpSprite);
}


sf::Sprite EnemyHpBar::getSprite() {
    return hpSprite;
}

void EnemyHpBar::setSprite(sf::String filename) {
    //setHpTexture(filename);
    hpTexture.loadFromFile("Sprites/HP_bar/" + filename);
    hpSprite.setTexture(hpTexture);
    hpSprite.setOrigin(hpTexture.getSize().x / 2, hpTexture.getSize().y / 2);
    EnemyHpBar::hpSprite = hpSprite;
}

void EnemyHpBar::setTexture(sf::String filename) {
    hpTexture.loadFromFile("Sprites/HP_bar/" + filename);
}

void EnemyHpBar::setHpOnBar(Enemy* enemy) {
	static int prevHp = 100;
	int hp = enemy->getHp();

	if (hp == 50) enemy->setStance50();
	else if (hp == 19) enemy->setStance90();



	if (hp != prevHp) {
		if (hp == 100) setSprite("HP_bar.png");
		else if (hp < 100 && hp >= 90) setSprite("HP_bar_90%.png");
		else if (hp < 90 && hp >= 80) setSprite("HP_bar_80%.png");
		else if (hp < 80 && hp >= 70) setSprite("HP_bar_75%.png");
		else if (hp < 70 && hp >= 60) setSprite("HP_bar_60%.png");
		else if (hp < 60 && hp >= 50) setSprite("HP_bar_50%.png");
		else if (hp < 50 && hp >= 40) setSprite("HP_bar_40%.png");
		else if (hp < 40 && hp >= 30) setSprite("HP_bar_30%.png");
		else if (hp < 30 && hp >= 20) setSprite("HP_bar_25%.png");
		else if (hp < 20 && hp >= 10) setSprite("HP_bar_15%.png");
		else if (hp < 10 && hp>0) setSprite("HP_bar_5%.png");
		else if (hp >= 0) setSprite("HP_bar_0%.png");
	}

	prevHp = hp;


}
