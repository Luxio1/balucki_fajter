#include <iostream>
#include "HpBar.hpp"
#include "Enemy.hpp"

HpBar::HpBar(sf::RenderWindow* window) {
	setSprite("HP_bar.png");
	this->window = window;
}

void HpBar::resetHealth() {
	setSprite("HP_bar.png");
}

void HpBar::setPosition(int x, int y)
{
    hpSprite.setPosition(x, y);
}

void HpBar::draw(){
    window->draw(this->hpSprite);
}


sf::Sprite HpBar::getSprite() {
    return hpSprite;
}

void HpBar::setSprite(sf::String filename) {
    //setHpTexture(filename);
    hpTexture.loadFromFile("Sprites/HP_bar/" + filename);
    hpSprite.setTexture(hpTexture);
    hpSprite.setOrigin(hpTexture.getSize().x / 2, hpTexture.getSize().y / 2);
    HpBar::hpSprite = hpSprite;
}

void HpBar::setTexture(sf::String filename) {
    hpTexture.loadFromFile("Sprites/HP_bar/" + filename);
}

void HpBar::setHpOnBar(int hp) {
	static int prevHp = 100;

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
