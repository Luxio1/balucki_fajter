//
// Created by bigel on 25.11.2020.
//

#include "Glove.h"


void Glove::gloveSetPosition(int baseWidth, int baseHeight) {
    glove.setPosition(baseWidth,baseHeight);
}

void Glove::gloveDraw(){
    window->draw(this->glove);
}

sf::FloatRect Glove::gloveGetGlobalBounds() {
    return glove.getGlobalBounds();
}
