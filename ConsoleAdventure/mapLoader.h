#ifndef MAPLOADER_H
#define MAPLOADER_H
#include <string>
#include <vector>

class mapLoader
{
    public:

    void loadNewMap(std::string mapToLoad, int health, std::vector<std::string>inventory, int posX, int posY);

    private:
};

#endif

