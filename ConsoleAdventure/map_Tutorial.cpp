#include "map_Tutorial.h"
#include "map_TutHouse.h"
#include "portalHandler.h"
#include "checkPlayerMovement.h"
#include <vector>
#include <windows.h>
#include <iostream>
#include <string>

int map_Tutorial::loadMap(std::string level, bool running, int health, int posx, int posy, int direction)
{
    level = "map_Tutorial";
    checkPlayerMovement check;
    portalHandler portal;
    map_TutHouse tutHouseObj;
    std::vector<std::vector<char>> map {{'#','#','#','#','#','#','#','#','#','#'},
                                       {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                                       {'#',' ',' ',' ',' ',' ','@',' ',' ','#'},        //     _
                                       {'#',' ',' ',' ','_',' ',' ',' ',' ','#'},        //   _-_-_     O = [5][4]
                                       {'#',' ','_','-','_','-','_',' ',' ','#'},        //  ||[_]||
                                       {'#','|','|','[','O',']','|','|',' ','#'},        //  **| |**
                                       {'#','*','*','|',' ','|','*','*',' ','#'},        //  **| |**
                                       {'#','*','*','|',' ','|','*','*',' ','#'},
                                       {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                                       {'#','#','#','#','#','#','#','#','#','#'}};
                                        std::string whichPortal;



    while(running)
    {
        for(int y = 0; y < 10; y++)
        {
            for(int x = 0; x < 10; x++)
            {
                if(map[y][x] == '@'){
                    posx = x;
                    posy = y;
                }
            }
        }

        system("cls");
        std::cout << "Health: " << health << std::endl;

        for(int i = 0; i < 10; i++)
        {
            std::cout << map[i][0] << map[i][1] << map[i][2] << map[i][3] << map[i][4] << map[i][5] << map[i][6] << map[i][7] << map[i][8] << map[i][9] << std::endl;
        }

        if(GetAsyncKeyState(VK_RIGHT))
        {
            direction = 1;
            if(check.checkMove(posx, posy, map, direction))
            {
                map[posy][posx] = ' ';
                map[posy][posx+1] = '@';
            }
            else
            {
                if(portal.handle(posx, posy, whichPortal, map, direction, level) == "tutHousePortal")
                {

                }
            }
        }

        if(GetAsyncKeyState(VK_LEFT))
        {
            direction = 2;
            if(check.checkMove(posx, posy, map, direction))
            {
                map[posy][posx] = ' ';
                map[posy][posx-1] = '@';
            }

        }

        if(GetAsyncKeyState(VK_UP))
        {
            direction = 3;
            if(check.checkMove(posx, posy, map, direction))
            {
                map[posy][posx] = ' ';
                map[posy-1][posx] = '@';
            }
            else
            {
                if(portal.handle(posx, posy, whichPortal, map, direction, level) == "tutHousePortal")
                {
                    tutHouseObj.tutHouse(running, health, posx, posy, direction, level);
                }
            }
        }

        if(GetAsyncKeyState(VK_DOWN))
        {
            direction = 4;
            if(check.checkMove(posx, posy, map, direction))
            {
                map[posy][posx] = ' ';
                map[posy+1][posx] = '@';
            }
        }
    }
}
