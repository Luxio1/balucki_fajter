#include <iostream>
#include "Background.hpp"

Background::Background(sf::RenderWindow* window) {

    backgroundTexture.loadFromFile("Sprites/Backgrounds/Office_scene.png");
    backgroundSprite.setTexture(backgroundTexture);
    this->window = window;

    scaleToWindow(window, getBackgroundSprites());
    setLabels();
}

// TODO: temporary function to test gloveSprite scaling
void Background::scaleToWindow(sf::RenderWindow* window, sf::Sprite toScale) {
    float scX = (float)window->getSize().x / toScale.getTexture()->getSize().x;
    float scY = (float)window->getSize().y / toScale.getTexture()->getSize().y;
    toScale.setScale(scX, scY);
}

sf::Sprite Background::getBackgroundSprites() {
    return backgroundSprite;
}


void Background::setLabels() {
    playerLabelTexture.loadFromFile("Sprites/HP_bar/player.png");
    enemyLabelTexture.loadFromFile("Sprites/HP_bar/enemy.png");
    playerLabelSprite.setTexture(playerLabelTexture);
    enemyLabelSprite.setTexture(enemyLabelTexture);
}

void Background::draw() {
    window->draw(this->backgroundSprite);
    window->draw(this->playerLabelSprite);
    window->draw(this->enemyLabelSprite);

}