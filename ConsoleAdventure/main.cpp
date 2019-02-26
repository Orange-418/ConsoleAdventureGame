#include <vector>
#include <tuple>
#include <string>
#include "map_TutorialIsland.h"
#include "map_TutorialIslandCleared.h"
#include "map_TutHouse.h"

class loadTutorial  //this class is just used for the tutorial
{
    public:
        std::tuple<std::string, int, std::vector<std::string>, int, int, bool> map_LoadTutorial(std::string mapToLoad, int health, std::vector<std::string>inventory, int posX, int posY, bool isPathCleared)
        {
            map_TutHouse loadTutHouse;
            map_TutorialIsland loadTutorialIsland;

            if(mapToLoad == "map_TutHouse")
            {
                std::tie(mapToLoad, health, inventory, posX, posY, isPathCleared) = loadTutHouse.loadMap(health, inventory, posX, posY, isPathCleared);
                return std::make_tuple(mapToLoad, health, inventory, posX, posY, isPathCleared);
            }
            if(mapToLoad == "map_TutorialIsland")
            {
                std::tie(mapToLoad, health, inventory, posX, posY) = loadTutorialIsland.loadMap(health, inventory, posX, posY);
                return std::make_tuple(mapToLoad, health, inventory, posX, posY, isPathCleared);
            }
        }

    private:

};

class mapLoad
{
    public:

        std::tuple<std::string, int, std::vector<std::string>, int, int> loadNewMap(std::string mapToLoad, int health, std::vector<std::string>inventory, int posX, int posY)
        {
            map_TutorialIslandCleared loadTutorialIslandClear;
            map_TutHouse loadTutHouse;

            if(mapToLoad == "map_TutorialIslandCleared")
            {
                std::tie(mapToLoad, health, inventory, posX, posY) = loadTutorialIslandClear.loadMap(health, inventory, posX, posY);
                return std::make_tuple(mapToLoad, health, inventory, posX, posY);
            }

            if(mapToLoad == "map_TutHouse")
            {
                std::tie(mapToLoad, health, inventory, posX, posY, isPathCleared) = loadTutHouse.loadMap(health, inventory, posX, posY, isPathCleared);
                return std::make_tuple(mapToLoad, health, inventory, posX, posY);
            }
        }

    private:

        bool isPathCleared = true;  //useless variable, but required to call the tutmap
};



int main()
{
    int posX = 1;
    int posY = 1;
    int health = 100;
    std::vector<std::string> inventory {"piece of lent"};
    std::string mapToLoad = "map_TutorialIsland";
    bool isPathCleared = false;
    bool running = true;

    mapLoad load;
    loadTutorial loadTut;

    while(!isPathCleared)
    {
        std::tie(mapToLoad, health, inventory, posX, posY, isPathCleared) = loadTut.map_LoadTutorial(mapToLoad, health, inventory, posX, posY, isPathCleared);
    }

    while(running)
    {
        std::tie(mapToLoad, health, inventory, posX, posY) = load.loadNewMap(mapToLoad, health, inventory, posX, posY);
    }
    return 0;
}




//fix double characters by making a checkfordouble function, return true and continue with key input
