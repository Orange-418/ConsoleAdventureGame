#include "mapLoader.h"
#include "map_TutHouse.h"
#include "map_TutorialIsland.h"

void mapLoader::loadNewMap(std::string mapToLoad, int health, std::vector<std::string>inventory, int posX, int posY)
{
    map_TutorialIsland loadTutorialIsland;
    map_TutHouse loadTutHouse;

    if(mapToLoad == "map_TutHouse")
    {
        loadTutHouse.loadMap(health, inventory, posX, posY);
    }

    if(mapToLoad == "map_TutorialIsland")
    {
        loadTutorialIsland.loadMap(health, inventory, posX, posY);
    }
}
