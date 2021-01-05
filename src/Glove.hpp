#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Glove {
private:
    sf::Texture gloveTexture;
	sf::Texture attackTexture;
    sf::Sprite gloveSprite;
    sf::RenderWindow *window;

    std::string filePath = "C:/Users/pmorl/Desktop/balucki_fajter";

public:
    Glove(sf::RenderWindow* window);

	void setAttackTexture();
	void setDefenceTexture();

    void setPosition(int baseWidth, int baseHeight);

    void draw();

    sf::FloatRect getGlobalBounds();
};

