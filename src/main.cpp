#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Camera.hpp"
#include "Enemy.hpp"
#include "EnemyHpBar.hpp"
#include "PlayerHpBar.hpp"
#include "Player.hpp"
#include "ActionSprite.hpp"
#include "Background.hpp"
#include "Glove.hpp"
#include "PlayAgain.hpp"
#include "Shield.hpp"

using namespace cv;
using namespace std;


int SLEEP_TIME = 5;
int INPUT_COUNTDOWN = 4;

enum playerMode {
    ATTACK_MODE,
    DEFENSE_MODE
};



int main(int argc, char** argv) {

    //Game Window
    int baseWidth = 1920;
    int baseHeight = 1080;
    sf::RenderWindow window(sf::VideoMode(baseWidth, baseHeight, 32), "Balucki fajter");

    //Player mode
    playerMode playerMode;

    //Background
    Background background(&window);
    sf::Sprite backgroundSprite = background.getBackgroundSprites();
    
    //Player
    Player player;

    //Enemy
    Enemy enemy(&window);
    
    //HP bar
    PlayerHpBar playerHpBar(&window);
    EnemyHpBar enemyHpBar(&window);

    //Action Sprite
    ActionSprite actionSprite(&window);

    //Shield Sprite
    Shield shield(&window);

    //Glove
    Glove glove(&window);

    //Photo and camera
    Camera camera;

    //play again
    PlayAgain playAgain(&window);
    playAgain.setPlayAgainSetPosition(baseWidth, baseHeight);

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

    while (window.isOpen()) {
        //Event polling (to event variable)
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                break;
            }
        }

        
        glove.gloveSetPosition(gloveX, gloveY);

        playerHpBar.hpSetPosition(baseWidth, baseHeight);
        enemyHpBar.hpSetPosition(baseWidth, baseHeight);

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

        //window.clear(sf::Color::Black);
        glove.gloveSetPosition(gloveX,  gloveY);

        playerHpBar.hpSetPosition(baseWidth, baseHeight);
        enemyHpBar.hpSetPosition(baseWidth, baseHeight);

        int szer = 0, wys = 0;
        camera.runWithVideoSingleFrame(&gloveX, &gloveY, &szer, &wys);
        gloveX = ((float)gloveX / szer) * baseWidth;
        gloveY = ((float)gloveY / wys) * baseHeight;

        //cout << "window x: " << window.getSize().x << " window y: " << window.getSize().y << endl;
        //cout << "x: " << gloveX << " y: " << gloveY << endl;

        if (camera.isBlow())
            glove.gloveAttackTex();
        else
            glove.gloveDefenceTex();

        rand = enemy.getRandom();
        
        if (rand == 0) {
            playerMode = DEFENSE_MODE;
        }
        else {
            playerMode = ATTACK_MODE;
        }

        if (enemy.isCollision(glove.getGlobalBounds(), enemy.getEnemySprite().getGlobalBounds()) && camera.isBlow()) {
            enemy.setHp();
            spriteTime = 10;
            enemy.setHitStance();
            framesAfterHit = 5;
        }

        enemyTime = enemy.makeMovableEnemyStance(enemyTime);
        enemyTime++;

        window.draw(backgroundSprite);
        
        if (framesAfterHit-- == 0) {
            enemy.setStance();
            enemy.setNewPostion(baseWidth, baseHeight);
        }

        enemy.setPosition();

        enemy.draw();

        enemyHpBar.dropHpOnBar(&enemy); //TODO: zmiana nazwy dropHpOnBar na bardziej odpowiednia
        playerHpBar.dropHpOnBar(&player);

        enemyHpBar.hpBarDraw();
        playerHpBar.hpBarDraw();

        if (spriteTime > 0) {
            actionSprite.drawActionSprite();
            spriteTime--;
        }
        else
            actionSprite.setSpritePosition(gloveX, gloveY);

        if (playerMode == DEFENSE_MODE) {

            shield.generateShieldPosition(baseWidth, baseHeight);
            shield.shieldDraw();

            if (!shield.isCollision(glove.getGlobalBounds(), shield.getGlobalBounds())) {
                    player.setHp(player.getHp() - 1);
            }

            framesAfterHit = 5;
        }

        if (enemy.getHp() <= 0 || player.getHp() <= 0) {
            enemy.setHitStance();
            
            if (enemy.getHp() <= 0) {
                playAgain.setHasWon(true);
            }
            else {
                playAgain.setHasWon(false);
            }

            playAgain.setPlayAgainSprite();
            playAgain.playAgainDraw();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                enemy.resetDamage();
                player.resetDamage();

                playerHpBar.resetHpBar();
                enemyHpBar.resetHpBar();

                enemy.setStance();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) break;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) break;

        glove.gloveDraw();

        window.display();

    }

    return 0;
}
