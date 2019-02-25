#include "map_TutorialIsland.h"
#include "map_TutHouse.h"
#include "checkNextBlock.h"
#include "inputHandler.h"
#include "windows.h"
#include "mapLoader.h"

void map_TutorialIsland::moveCursor(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void map_TutorialIsland::hideCursor()
{
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = false;
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void map_TutorialIsland::loadMap(int health, std::vector<std::string> inventory, int posX, int posY)
{
    checkNextBlock checkBlock;
    inputHandler userPos;
    mapLoader load;
    map_TutHouse TutHouse;

    hideCursor();

    pathCleared = TutHouse.isPathCleared();
    playerX = userPos.returnX(map, sizeX, sizeY);
    playerY = userPos.returnY(map, sizeX, sizeY);

    map[playerY][playerX] = ' ';
    map[posY][posX] = '@';
    //status = "*You see a house... You might be able to go inside*";

    if(pathCleared)
    {
        map[1][0] = 'O';
        status = "sadfdf";
    }

    system("cls");
    Sleep(125);

    while(running)
    {
        playerX = userPos.returnX(map, sizeX, sizeY);
        playerY = userPos.returnY(map, sizeX, sizeY);

        if(GetAsyncKeyState(VK_RIGHT) && !GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_DOWN))
        {
            if(checkBlock.checkNext(map[playerY][playerX+1]) == true)
            {
                map[playerY][playerX] = ' ';
                map[playerY][playerX+1] = '@';

                Sleep(gameSpeed);
            }
            else
            {
                if(playerX == houseX+1 && playerY == houseY)
                {
                    posX = 1;
                    posY = 3;
                    load.loadNewMap("map_TutHouse", health, inventory, posX, posY);
                }
            }
        }

        if(GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_DOWN))
        {
            if(checkBlock.checkNext(map[playerY][playerX-1]) == true)
            {
                map[playerY][playerX] = ' ';
                map[playerY][playerX-1] = '@';
                Sleep(gameSpeed);
            }
            else
            {
                if(playerX == houseX-1 && playerY == houseY)
                {
                    posX = 1;
                    posY = 3;
                   load.loadNewMap("map_TutHouse", health, inventory, posX, posY);
                }
            }
        }

        if(GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT) && !GetAsyncKeyState(VK_DOWN))
        {
            if(checkBlock.checkNext(map[playerY-1][playerX]) == true)
            {
                map[playerY][playerX] = ' ';
                map[playerY-1][playerX] = '@';
                Sleep(gameSpeed);
            }
            else
            {
                if(playerX == houseX && playerY-1== houseY)
                {
                    posX = 1;
                    posY = 3;
                    load.loadNewMap("map_TutHouse", health, inventory, posX, posY);
                }
            }
        }

        if(GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_RIGHT) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_LEFT))
        {
            if(checkBlock.checkNext(map[playerY+1][playerX]) == true)
            {
                map[playerY][playerX] = ' ';
                map[playerY+1][playerX] = '@';
                Sleep(gameSpeed);
            }
            else
            {
                if(playerX == houseX && playerY+1 == houseY)
                {
                    posX = 1;
                    posY = 3;
                    load.loadNewMap("map_TutHouse", health, inventory, posX, posY);
                }
            }
        }

        for(int x = 0; x < sizeX; x++)
        {
            for(int y = 0; y < sizeY; y++)
            {
                moveCursor(x, y);
                std::cout << map[y][x];
                std::cout<<std::endl;
            }
        }
        std::cout<<std::endl;
        std::cout << status << std::endl;

    }
}
