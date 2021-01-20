#include <iostream>
#include "GameLoop.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

   
    //Game Window
    int baseWidth = 1920;
    int baseHeight = 1080;
    sf::RenderWindow window(sf::VideoMode(baseWidth, baseHeight, 32), "Balucki fajter");

    GameLoop lunchGame(&window);
    lunchGame.launch();
    return 0;
}
