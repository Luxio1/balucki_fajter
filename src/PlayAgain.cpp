#include "PlayAgain.hpp"
#include <iostream>
#include <time.h>
#include "Enemy.hpp"

PlayAgain::PlayAgain(sf::RenderWindow* window) {
    this->window = window;
}


void PlayAgain::playAgainPopUpSetPosition(int baseWidth, int baseHeight) {
    playAgainPopUpSprite.setPosition(baseWidth / 2, baseHeight / 2 );
}


void PlayAgain::setPlayAgainSetPosition(int baseWidth, int baseHeight) {
    playAgainPopUpSetPosition(baseWidth, baseHeight);
}

void PlayAgain::playAgainPopUpDraw() {
    window->draw(this->playAgainPopUpSprite);
}

void PlayAgain::playAgainDraw(){
    playAgainPopUpDraw();
}

void PlayAgain::setPlayAgainSprite() {
    setPlayAgainPopUpTexture();
    playAgainPopUpSprite.setTexture(playAgainPopUpTexture);
    playAgainPopUpSprite.setOrigin(playAgainPopUpTexture.getSize().x / 2, playAgainPopUpTexture.getSize().y / 2);
    PlayAgain::playAgainPopUpSprite = playAgainPopUpSprite;

}

void PlayAgain::setPlayAgainPopUpTexture() {
    playAgainPopUpTexture.loadFromFile(filePath + "victory.png");
}




