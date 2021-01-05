#include "Glove.hpp"

Glove::Glove(sf::RenderWindow* window) {

    gloveTexture.loadFromFile(filePath + "/Sprites/rekawice/rekawica_lewa.png");
    attackTexture.loadFromFile(filePath + "/Sprites/rekawice/attack_pose_glove.png");
    gloveSprite.setTexture(gloveTexture);
    this->window = window;
    gloveSprite.setOrigin(gloveTexture.getSize().x / 2, gloveTexture.getSize().y / 2);
    gloveSprite.setScale(2, 2);
}

void Glove::gloveSetPosition(int baseWidth, int baseHeight) {
    gloveSprite.setPosition(baseWidth,baseHeight);
}

void Glove::gloveDraw(){
    window->draw(this->gloveSprite);
}

sf::FloatRect Glove::getGlobalBounds() {
    return gloveSprite.getGlobalBounds();
}

void Glove::gloveAttackTex() {
	gloveSprite.setTexture(attackTexture);
}
void Glove::gloveDefenceTex() {
	gloveSprite.setTexture(gloveTexture);
}
