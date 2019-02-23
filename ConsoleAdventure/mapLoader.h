#ifndef MAPLOADER_H
#define MAPLOADER_H
#include <string>

class mapLoader
{
    public:
        void load(std::string mapName);
        void mapSetter(std::string mapName);
        void healthSetter(int healthSet);
        std::string mapGetter();
        int healthGetter();

    private:
    bool running = true;
    int health = 100;
    int posx;
    int posy;
    int direction;
};

#endif // MAPLOADER_H
