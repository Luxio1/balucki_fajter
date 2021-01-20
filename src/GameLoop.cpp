#include <iostream>
#include "GameLoop.hpp"

using namespace cv;
using namespace std;

GameLoop::GameLoop(sf::RenderWindow* window) {
    this->window = window;
}



int GameLoop::launch() {

    //Player mode
    playerMode playerMode;

    //Background
    Background background(window);

    //Player
    Player player;

    //Enemy
    Enemy enemy(window);

    //HP bar
    HpBar playerHpBar(window);
    HpBar enemyHpBar(window);

    //Action Sprite
    ActionSprite actionSprite(window);

    //Shield Sprite
    Shield shield(window);

    //Glove
    Glove glove(window);

    //Photo and camera
    Camera camera;

    //play again
    PlayAgain playAgain(window);
    playAgain.setPosition(baseWidth, baseHeight);

    //Game loop
    sf::Event event{};
    int prevGloveX = 0;
    int prevGloveY = 0;
    int targetGloveX = 0;
    int targetGloveY = 0;
    int gloveX = 0;
    int gloveY = 0;
    int tempGloveV = 7;
    int inputGatherFrame = INPUT_COUNTDOWN;
    int szer = 0, wys = 0;
    int spriteTime = 0;
    int enemyTime = 0;
    int rand = -1;
    int framesAfterHit = -1;


    enemy.setBasePosition(baseWidth / 2, baseHeight);

    while ((*window).isOpen()) {
        //Event polling (to event variable)
        while ((*window).pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                (*window).close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    (*window).close();
                }
                break;
            }
        }


        glove.setPosition(gloveX, gloveY);

        if (--inputGatherFrame == 0) {
            inputGatherFrame = INPUT_COUNTDOWN;
            prevGloveX = gloveX;
            prevGloveY = gloveY;
            camera.runWithVideoSingleFrame(&gloveX, &gloveY, &szer, &wys);
            gloveX = ((float)gloveX / szer) * baseWidth;
            gloveY = ((float)gloveY / wys) * baseHeight;
            targetGloveX = gloveX;
            targetGloveY = gloveY;

            //anti-shaking solution
            if (abs(prevGloveX - gloveX) < 192) gloveX = prevGloveX;
            if (abs(prevGloveY - gloveY) < 108) gloveY = prevGloveY;
        }

        glove.setPosition(gloveX, gloveY);

        playerHpBar.setPosition(baseWidth * 1 / 4, baseHeight * 1 / 5);
        enemyHpBar.setPosition(baseWidth * 3 / 4, baseHeight * 1 / 5);

        int szer = 0, wys = 0;
        camera.runWithVideoSingleFrame(&gloveX, &gloveY, &szer, &wys);
        gloveX = ((float)gloveX / szer) * baseWidth;
        gloveY = ((float)gloveY / wys) * baseHeight;

        background.draw();
        playerMode = ATTACK_MODE;


        if (playAgain.isPlay() != false) {

            if (enemy.getHp() > 0 && player.getHp() > 0) {

                if (camera.isBlow())
                    glove.setAttackTexture();
                else
                    glove.setDefenceTexture();

                rand = enemy.getRandom();

                if (rand == 0) {
                    playerMode = DEFENSE_MODE;
                }
                else {
                    playerMode = ATTACK_MODE;
                }

                if (enemy.isCollision(glove.getGlobalBounds(), enemy.getEnemySprite().getGlobalBounds()) &&
                    camera.isBlow()) {
                    enemy.decreaseHp();
                    spriteTime = 10;
                    enemy.setHitStance();
                    framesAfterHit = 5;
                }

                enemyTime = enemy.makeMovableEnemyStance(enemyTime);
                enemyTime++;

                if (framesAfterHit-- == 0) {
                    enemy.setStance();
                    enemy.setNewPostion(baseWidth, baseHeight);
                }

                enemy.setPosition();

                enemyHpBar.setHpOnBar(enemy.getHp());
                playerHpBar.setHpOnBar(player.getHp());
            }

            enemy.draw();
            enemyHpBar.draw();
            playerHpBar.draw();
        }
        else {
            playAgain.setStartGame();
            playAgain.draw();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                playAgain.isGameStart();
            }
        }

        if (enemy.getHp() > 0 && player.getHp() > 0) {

            if (spriteTime > 0) {
                actionSprite.draw();
                spriteTime--;
            }
            else
                actionSprite.setPosition(gloveX, gloveY);

            if (playerMode == DEFENSE_MODE) {

                shield.generateShieldPosition(baseWidth, baseHeight);
                shield.draw();

                if (!shield.isCollision(glove.getGlobalBounds(), shield.getGlobalBounds())) {
                    player.setHp(player.getHp() - 1);
                }

                framesAfterHit = 5;
            }
        }

        glove.draw();

        if (enemy.getHp() <= 0 || player.getHp() <= 0) {
            enemy.setHitStance();

            if (enemy.getHp() <= 0) {
                playAgain.setHasWon(true);
            }
            else {
                playAgain.setHasWon(false);
            }

            playAgain.setSprite();
            playAgain.draw();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                enemy.resetDamage();
                player.resetDamage();

                playerHpBar.resetHealth();
                enemyHpBar.resetHealth();

                enemy.setStance();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) break;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) break;



        (*window).display();

    }

    return 0;
}


