#ifndef MAP_TUTHOUSE_H
#define MAP_TUTHOUSE_H
#include <iostream>
#include <thread>
#include <vector>

class map_TutHouse
{
    public:

        void moveCursor(int x, int y);
        void hideCursor();
        void loadMap(int health, std::vector<std::string>inventory, int posX, int posY);
        bool isPathCleared();

    private:
        std::string status;
        int gameSpeed = 40;
        int doorX = 1;
        int doorY = 4;
        int playerX;
        int playerY;
        int tutMasterX = 2;
        int tutMasterY = 3;
        int writeX;
        int writeY;
        int sizeX = 6;
        int sizeY = 5;
        bool running = true;
        bool pathCleared = false;

        std::vector<std::vector<char>> map {{'#','#','#','#','#','#'},
                                            {'#',' ',' ',' ',' ','#'},  //  person coords: [3][2]
                                            {'#',' ',' ','&',' ','#'},  //
                                            {'#','@',' ',' ',' ','#'},  //
                                            {'#','O','#','#','#','#'}};
};

#endif // MAP_TUTHOUSE_H
