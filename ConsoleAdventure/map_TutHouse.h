#ifndef MAP_TUTHOUSE_H
#define MAP_TUTHOUSE_H
#include <iostream>
#include <thread>
#include <vector>
#include <tuple>

class map_TutHouse
{
    public:

        bool nextToTutMaster(std::vector<std::vector<char>> map, int playerX, int playerY);
        void moveCursor(int x, int y);
        void hideCursor();
        std::tuple<std::string, int, std::vector<std::string>, int, int, bool> loadMap(int health, std::vector<std::string>inventory, int posX, int posY, bool isCleared);

    private:
        std::string status;
        std::string mapToLoad;
        int gameSpeed = 40;
        int doorX = 1;
        int doorY = 4;
        int playerX;
        int playerY;
        int tutMasterX = 3;
        int tutMasterY = 2;
        int writeX;
        int writeY;
        int sizeX = 6;
        int sizeY = 5;
        bool running = true;

        std::vector<std::vector<char>> map {{'#','#','#','#','#','#'},
                                            {'#',' ',' ',' ',' ','#'},  //  person coords: [3][2]
                                            {'#',' ',' ','&',' ','#'},  //
                                            {'#','@',' ',' ',' ','#'},  //
                                            {'#','O','#','#','#','#'}};
};

#endif // MAP_TUTHOUSE_H
