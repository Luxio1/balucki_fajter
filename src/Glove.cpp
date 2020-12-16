#include "Glove.hpp"

Glove::Glove(sf::RenderWindow* window) {

    gloveTexture.loadFromFile(filePath + "/Sprites/rekawice/rekawica_lewa.png");
    attackTexture.loadFromFile(filePath + "/Sprites/rekawice/attack_pose_glove.png");
    glove.setTexture(gloveTexture);
    this->window = window;
    glove.setOrigin(gloveTexture.getSize().x / 2, gloveTexture.getSize().y / 2);
    glove.setScale(2, 2);
}

void Glove::gloveSetPosition(int baseWidth, int baseHeight) {
    glove.setPosition(baseWidth,baseHeight);
}

void Glove::gloveDraw(){
    window->draw(this->glove);
}

sf::FloatRect Glove::gloveGetGlobalBounds() {
    return glove.getGlobalBounds();
}

void Glove::gloveAttackTex() {
	glove.setTexture(attackTexture);
}
void Glove::gloveDefenceTex() {
	glove.setTexture(gloveTexture);
}
