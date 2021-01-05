#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Enemy {
private:
    int HP = 100;
    int enemyTime = 0;
    int enemyPositionX;
    int enemyPositionY;
    int isAttack = -1;

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

    std::string filePath = "C:/Users/pmorl/Desktop/balucki_fajter/Sprites/Fighters/";

public:
    Enemy(sf::RenderWindow* window);

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

    int getRandom();

    void enemyAttack();
};