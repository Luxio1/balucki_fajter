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

void PlayAgain::setHasWon(bool has_won) {
    this->has_player_won = has_won;
}

void PlayAgain::setPlayAgainSprite() {
    if (this->has_player_won == true) {
        setVictoryPlayAgainPopUpTexture();
    }
    else {
        setLostPlayAgainPopUpTexture();
    }

    playAgainPopUpSprite.setTexture(playAgainPopUpTexture);
    playAgainPopUpSprite.setOrigin(playAgainPopUpTexture.getSize().x / 2, playAgainPopUpTexture.getSize().y / 2);
    PlayAgain::playAgainPopUpSprite = playAgainPopUpSprite;

}

void PlayAgain::setVictoryPlayAgainPopUpTexture() {
    playAgainPopUpTexture.loadFromFile(filePath + "victory.png");
}

void PlayAgain::setLostPlayAgainPopUpTexture() {
    playAgainPopUpTexture.loadFromFile(filePath + "lost.png");
}




