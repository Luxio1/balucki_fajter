#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Enemy.hpp"

class Enemy {
private:
    //int x, y;
    //bool is_blocking;

    int HP = 100;
    int enemyTime = 0;
    int enemyPositionX;
    int enemyPositionY;

    sf::Texture enemyTexture;
    sf::Sprite enemySprite;
    sf::RenderWindow *window;

    sf::Texture enemyTextureHigh;
    sf::Texture enemyTextureLow;
    sf::Texture enemyStanceHighT;
    sf::Texture enemyStanceLowT;
    sf::Texture enemyStanceHitT;
    sf::Texture enemyStanceAttackT;
    sf::Texture enemyStanceHit2T;

    std::string filePath = "C:/Users/bigel/balucki_fajter/Sprites/Fighters/";

public:
    Enemy(sf::RenderWindow *window) {
        //enemyTexture.loadFromFile(filePath + "/Sprites/Fighters/frajer_fajter1cropped.png");
        //enemySprite.setTexture(enemyTexture);

        //enemySprite.setOrigin(enemyTexture.getSize().x / 2, enemyTexture.getSize().y / 2);
        enemyStanceHighT.loadFromFile(filePath + "frajer_fajter1cropped.png");
        enemyStanceLowT.loadFromFile(filePath + "frajer_fajter2cropped.png");
        enemyStanceHitT.loadFromFile(filePath + "frajer_fajter1_attackedt.png");
        enemyStanceHit2T.loadFromFile(filePath + "frajer_fajter1_attacked2.png");
        enemyStanceAttackT.loadFromFile(filePath + "frajer_fajter_attack_cropped.png");
        enemyStanceSet();
        this->window = window;
    }

    void enemySetPosition();
    void enemySetBasePosition(int baseWidth, int baseHeight);
    void enemyDraw();

    bool isCollision(sf::FloatRect gloveBoundingBox, sf::FloatRect fighter1BoundingBox);

    sf::Sprite getEnemySprite();

    int getHp() const;
    void setHp();

    void setEnemySprite();

    void enemyStanceHigh();

    void enemyStanceLow();

    int enemyStance(int enemyTime);

    void enemyNewPosition(int baseWidth, int baseHeight);

    void enemyAttackSetSprite();

    void enemyStance90();

    void enemyStance50();

    void enemyStanceHit();

    void enemyStanceSet();

    void resetDamage();
};