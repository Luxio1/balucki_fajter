#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Background {
private:
    //int x, y;
    //bool is_blocking;

    int HP = 100;

    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::RenderWindow *window;

    std::string filePath = "C:/Users/pmorl/Desktop/balucki_fajter";

public:
    Background(sf::RenderWindow* window);

    sf::Sprite getBackgroundSprites();

    void scaleToWindow(sf::RenderWindow *window, sf::Sprite toScale);
};


