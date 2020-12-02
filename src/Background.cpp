#include <iostream>
#include "Background.h"

// temporary function to test gloveSprite scaling
void Background::scaleToWindow(sf::RenderWindow* window, sf::Sprite toScale) {
    float scX = (float)window->getSize().x / toScale.getTexture()->getSize().x;
    float scY = (float)window->getSize().y / toScale.getTexture()->getSize().y;
    toScale.setScale(scX, scY);
}

sf::Sprite Background::getBackgroundSprites() {
    return background;
}