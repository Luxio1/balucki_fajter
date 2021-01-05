#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Glove {
private:
    //int x, y;
    //bool is_blocking;

    int HP = 100;

    sf::Texture gloveTexture;
	sf::Texture attackTexture;
    sf::Sprite gloveSprite;
    sf::RenderWindow *window;

    std::string filePath = "C:/Users/pmorl/Desktop/balucki_fajter";

public:
    Glove(sf::RenderWindow* window);

	void gloveAttackTex();
	void gloveDefenceTex();

    void gloveSetPosition(int baseWidth, int baseHeight);

    void gloveDraw();

    sf::FloatRect getGlobalBounds();
};

