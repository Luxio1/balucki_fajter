#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Enemy.hpp"

class Enemy {
private:
	//int x, y;
	//bool is_blocking;

	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
	sf::RenderWindow *window;

	std::string filePath = "C:/Users/pmorl/Desktop/balucki_fajter";

public:
	Enemy(sf::RenderWindow *window) {
		enemyTexture.loadFromFile(filePath + "/Sprites/Fighters/frajer_fajter1.png");
		enemySprite.setTexture(enemyTexture);
		enemySprite.setOrigin(enemyTexture.getSize().x / 2, enemyTexture.getSize().y / 2);
		this->window = window;
	}

	void enemySetPosition(int baseWidth, int baseHeight);
	void enemyDraw();
};