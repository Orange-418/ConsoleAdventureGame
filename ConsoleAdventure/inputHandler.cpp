#include "inputHandler.h"

int inputHandler::returnX(std::vector<std::vector<char>> map, int sizeX, int sizeY)
{
    for(int x = 0; x < sizeX; x++)
    {
        for(int y = 0; y < sizeY; y++)
        {
            if(map[y][x] == '@')
            {
                return x;
            }
        }
    }
}

int inputHandler::returnY(std::vector<std::vector<char>> map, int sizeX, int sizeY)
{
    for(int x = 0; x < sizeX; x++)
    {
        for(int y = 0; y < sizeY; y++)
        {
            if(map[y][x] == '@')
            {
                return y;
            }
        }
    }
}
