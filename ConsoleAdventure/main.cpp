#include <iostream>
#include <string>
#include <windows.h>
#include "checkPlayerMovement.h"
#include "map_Tutorial.h"

//1 = right
//2 = left
//3 = up
//4 = down


int main()
{
    map_Tutorial tutorial;
    std::string level;
    bool running = true;
    int health = 100;
    int posx;
    int posy;
    int direction;

    tutorial.loadMap(level, running, health, posx, posy, direction);

    return 0;
}
