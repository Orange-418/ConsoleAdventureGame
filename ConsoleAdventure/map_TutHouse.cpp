#include "map_TutHouse.h"
#include "map_TutorialIsland.h"
#include "checkNextBlock.h"
#include "inputHandler.h"
#include "npc_TutorialMaster.h"
#include "windows.h"
#include "mapLoader.h"

void map_TutHouse::moveCursor(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void map_TutHouse::hideCursor()
{
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = false;
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void map_TutHouse::loadMap(int health, std::vector<std::string>inventory, int posX, int posY)
{
    map_TutorialIsland tutIsland;
    checkNextBlock checkBlock;
    inputHandler userPos;
    mapLoader load;
    npc_TutorialMaster talkTutMaster;

    hideCursor();

    playerX = userPos.returnX(map, sizeX, sizeY);
    playerY = userPos.returnY(map, sizeX, sizeY);

    map[playerY][playerX] = ' ';
    map[posY][posX] = '@';
    status = "*There's a man standing in the middle of the room. Maybe I can use [Enter] to talk to him*";

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
                if(playerX+1 == doorX && playerY == doorY)
                {
                    posX = 7;
                    posY = 6;
                    load.loadNewMap("map_TutorialIsland", health, inventory, posX, posY);
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
                if(playerX-1 == doorX && playerY == doorY)
                {
                    posX = 7;
                    posY = 6;
                    load.loadNewMap("map_TutorialIsland", health, inventory, posX, posY);
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
                if(playerX == doorX && playerY-1 == doorY)
                {
                    posX = 7;
                    posY = 6;
                    load.loadNewMap("map_TutorialIsland", health, inventory, posX, posY);
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
                if(playerX == doorX && playerY+1 == doorY)
                {
                    posX = 7;
                    posY = 6;
                    load.loadNewMap("map_TutorialIsland", health, inventory, posX, posY);
                }
            }
        }

        if(GetAsyncKeyState(VK_RETURN))
        {
            if(playerX+1 == tutMasterX || playerX-1 == tutMasterX || playerY+1 == tutMasterY || playerY-1 == tutMasterY)
            {
                pathCleared = talkTutMaster.interact();
                system("cls");
                Sleep(75);
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

bool map_TutHouse::isPathCleared()
{
    return pathCleared;
}
