#include <iostream>
#include "Player.hpp"

Player::Player() {
    setHp(100);
}

void Player::setHp(int HP) {
    this->HP = HP;
}

int Player::getHp() {
    return HP;
}

void Player::resetDamage() {
    this->setHp(100);
}
