#include "mapLoader.h"
#include "map_Tutorial.h"
#include "map_TutHouse.h"
#include <iostream>
void mapLoader::load(std::string mapName)
{
    map_Tutorial tutorial;
    map_TutHouse tutHouseMap;

    if(mapName == "map_Tutorial")
    {
        tutorial.loadMap(running, health, posx, posy, direction);

    }

    if(mapName == "map_TutHouse")
    {
        tutHouseMap.tutHouse(running, health, posx, posy, direction);
    }
}

void mapLoader::mapSetter(std::string mapName)
{
    //level = mapName;
}

std::string mapLoader::mapGetter()
{
    //return level;
}

void mapLoader::healthSetter(int healthSet)
{
    //healthSet = health;
}

int mapLoader::healthGetter()
{
    //return health;
}
