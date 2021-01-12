#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Background {
private:
    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::RenderWindow *window;

public:
    Background(sf::RenderWindow* window);

    sf::Sprite getBackgroundSprites();

    void scaleToWindow(sf::RenderWindow *window, sf::Sprite toScale);
};


