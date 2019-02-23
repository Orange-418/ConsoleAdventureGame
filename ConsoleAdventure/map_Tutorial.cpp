#include "map_Tutorial.h"
#include "map_TutHouse.h"
#include "checkPlayerMovement.h"
#include "mapLoader.h"
#include <vector>
#include <windows.h>
#include <iostream>


int map_Tutorial::loadMap(bool running, int health, int posx, int posy, int direction)
{
    checkPlayerMovement check;
    map_TutHouse tutHouseObj;
    mapLoader loadMap;

    std::vector<std::vector<char>> map {{'#','#','#','#','#','#','#','#','#','#'},
                                       {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                                       {'#',' ','@',' ',' ',' ',' ',' ',' ','#'},        //     _
                                       {'#',' ',' ',' ','_',' ',' ',' ',' ','#'},        //   _-_-_     O = [5][4] (map_TutHouse coords)
                                       {'#',' ','_','|','_','|','_',' ',' ','#'},        //  ||[_]||
                                       {'#','|','|',' ','O',' ','|','|',' ','#'},        //  **| |**
                                       {'#','*','*','|',' ','|','*','*',' ','#'},        //  **| |**
                                       {'#','*','*','|',' ','|','*','*',' ','#'},
                                       {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                                       {'#','#','#','#','#','#','#','#','#','#'}};
    while(running)
    {
        for(int y = 0; y < 10; y++)     //collect the x and y coordinates for player position
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

        for(int i = 0; i < 10; i++)     //print out the map
        {
            std::cout << map[i][0] << map[i][1] << map[i][2] << map[i][3] << map[i][4] << map[i][5] << map[i][6] << map[i][7] << map[i][8] << map[i][9] << std::endl;
        }

        if(GetAsyncKeyState(VK_RIGHT))      //if keystroke is right arrow key, move the player
        {
            direction = 1;
            if(check.checkMove(posx, posy, map, direction))     //check to see if movement is possible
            {
                map[posy][posx] = ' ';
                map[posy][posx+1] = '@';
            }
            else
            {
                if(map[posy][posx+1] == 'O')       //if movement is impossible and player is next to a portal, teleport
                {
                    if(posy == 5 && posx+1 == 4)
                    {
                        loadMap.load("map_TutHouse");
                    }
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
            else
            {
                if(map[posy][posx-1] == 'O')       //if movement is impossible and player is next to a portal, teleport
                {
                    if(posy == 5 && posx-1 == 4)
                    {
                        loadMap.load("map_TutHouse");
                    }
                }
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
                if(map[posy-1][posx] == 'O')       //if movement is impossible and player is next to a portal, teleport
                {
                    if(posy-1 == 5 && posx == 4)
                    {
                        loadMap.load("map_TutHouse");
                    }
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
            else
            {
                if(map[posy+1][posx] == 'O')       //if movement is impossible and player is next to a portal, teleport
                {
                    if(posy+1 == 5 && posx == 4)
                    {
                        loadMap.load("map_TutHouse");
                    }
                }
            }
        }
    }
}
