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
    sf::Sprite glove;
    sf::RenderWindow *window;

    std::string filePath = "C:/Users/bigel/balucki_fajter";

public:
    Glove(sf::RenderWindow *window) {

        gloveTexture.loadFromFile(filePath + "/Sprites/rekawice/rekawica_lewa.png");
        glove.setTexture(gloveTexture);
        this->window = window;
        glove.setOrigin(gloveTexture.getSize().x / 2, gloveTexture.getSize().y / 2);
        glove.setScale(2, 2);
    }


    void gloveSetPosition(int baseWidth, int baseHeight);

    void gloveDraw();

    sf::FloatRect gloveGetGlobalBounds();
};

