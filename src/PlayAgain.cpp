#include "PlayAgain.hpp"
#include <iostream>
#include <time.h>
#include "Enemy.hpp"

PlayAgain::PlayAgain(sf::RenderWindow* window) {
    this->window = window;
    this->has_player_won;
}


void PlayAgain::setPosition(int baseWidth, int baseHeight) {
    playAgainPopUpSprite.setPosition(baseWidth / 2, baseHeight / 2);
}

void PlayAgain::draw() {
    window->draw(this->playAgainPopUpSprite);
}

void PlayAgain::setHasWon(bool has_won) {
    this->has_player_won = has_won;
}

void PlayAgain::setStartGame() {
    playAgainPopUpTexture.loadFromFile("Sprites/play_again/start.png");
    playAgainPopUpSprite.setTexture(playAgainPopUpTexture);
    playAgainPopUpSprite.setOrigin(playAgainPopUpTexture.getSize().x / 2, playAgainPopUpTexture.getSize().y / 2);
    PlayAgain::playAgainPopUpSprite = playAgainPopUpSprite;
}

void PlayAgain::isGameStart() {
    this->play = true;
}

void PlayAgain::setSprite() {
    if (this->has_player_won == true) {
        setVictoryTexture();
    }
    else {
        setLostTexture();
    }

    playAgainPopUpSprite.setTexture(playAgainPopUpTexture);
    playAgainPopUpSprite.setOrigin(playAgainPopUpTexture.getSize().x / 2, playAgainPopUpTexture.getSize().y / 2);
    PlayAgain::playAgainPopUpSprite = playAgainPopUpSprite;

}

void PlayAgain::setVictoryTexture() {
    playAgainPopUpTexture.loadFromFile("Sprites/play_again/victory.png");
}

void PlayAgain::setLostTexture() {
    playAgainPopUpTexture.loadFromFile("Sprites/play_again/lost.png");
}

bool PlayAgain::isPlay() const {
    return play;
}
