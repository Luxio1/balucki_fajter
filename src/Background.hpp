#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Background {
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::RenderWindow *window;


    sf::Texture enemyLabelTexture;
    sf::Sprite enemyLabelSprite;

    sf::Texture playerLabelTexture;
    sf::Sprite playerLabelSprite;

public:
    Background(sf::RenderWindow* window);

    sf::Sprite getBackgroundSprites();

    void scaleToWindow(sf::RenderWindow *window, sf::Sprite toScale);
    void setLabels();
    void draw();
};


