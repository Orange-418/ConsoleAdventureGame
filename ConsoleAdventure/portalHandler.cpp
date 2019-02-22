#include "portalHandler.h"

std::string portalHandler::handle(int posx, int posy, std::string whichPortal, std::vector<std::vector<char>> map, int direction, std::string level)
{
    if(level == "map_Tutorial"){
    if(direction == 1)
    {
        if(map[posy][posx+1] == 'O')
        {
            for(int y = 0; y < 10; y++)
            {
                for(int x = 0; x < 10; x++)
                {
                    if(map[y][x] == '@')
                    {
                        if(y == 5 && x+1 == 4)
                        {
                            return "tutHousePortal";
                        }
                    }
                }
            }
        }
        else
        {
            return "";
        }
    }

    if(direction == 3)
    {
        if(map[posy-1][posx] == 'O')
        {
            for(int y = 0; y < 10; y++)
            {
                for(int x = 0; x < 10; x++)
                {
                    if(map[y][x] == '@')
                    {
                        if(y-1 == 5 && x == 4)
                        {
                            return "tutHousePortal";
                        }
                    }
                }
            }
        }
        else
        {
            return "";
        }
    }
    }

    if(level == "map_TutHouse")
    {
           /* if(map[posy][posx+1] == 'O')
        {
            for(int y = 0; y < 10; y++)
            {
                for(int x = 0; x < 10; x++)
                {
                    if(map[y][x] == '@')
                    {
                        if(y == 5 && x+1 == 4)
                        {
                            return "tutMapPortal";
                        }
                    }
                }
            }
        }
        else
        {
            return "";
        }*/


    if(direction == 3)
    {
        if(map[posy-1][posx] == 'O')
        {
            for(int y = 0; y < 10; y++)
            {
                for(int x = 0; x < 10; x++)
                {
                    if(map[y][x] == '@')
                    {
                        if(y-1 == 9 && x == 4)
                        {
                            return "tutMapPortal";
                        }
                    }
                }
            }
        }
        else
        {
            return "";
        }
    }
    if(direction == 4)
    {
        if(map[posy+1][posx] == 'O')
        {
            for(int y = 0; y < 10; y++)
            {
                for(int x = 0; x < 10; x++)
                {
                    if(map[y][x] == '@')
                    {
                        if(y+1 == 9 && x == 4)
                        {
                            return "tutMapPortal";
                        }
                    }
                }
            }
        }
        else
        {
            return "";
        }
    }
    }
    }

