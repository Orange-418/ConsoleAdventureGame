#include <vector>
#include <string>
#include "map_TutorialIsland.h"
#include "mapLoader.h"

int main()
{
    int posX = 1;
    int posY = 1;
    int health = 100;
    std::vector<std::string> inventory;

    mapLoader load;

    load.loadNewMap("map_TutorialIsland", health, inventory, posX, posY);

    return 0;
}




//fix double characters by making a checkfordouble function, return true and continue with key input
