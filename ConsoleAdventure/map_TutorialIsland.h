#ifndef MAP_TUTORIALISLAND_H
#define MAP_TUTORIALISLAND_H
#include <iostream>
#include <thread>
#include <vector>

class map_TutorialIsland
{
    public:

    void moveCursor(int x, int y);
    void hideCursor();
    void loadMap(int health, std::vector<std::string> inventory, int posX, int posY);
    void setPathCleared(bool cleared);

    private:
        std::string status;
        int gameSpeed = 40;
        int houseX = 7;
        int houseY = 5;
        int playerX;
        int playerY;
        int writeX;
        int writeY;
        int sizeX = 20;
        int sizeY = 10;
        bool running = true;
        bool pathCleared = false;

        std::vector<std::vector<char>> map {{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                                            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //
                                            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //
                                            {'#',' ','@',' ',' ',' ',' ','_',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //  ___
                                            {'#',' ',' ',' ',' ','_','-','_','-','_',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //  |_|
                                            {'#',' ',' ',' ','|',' ','[','O',']',' ','|',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //  |O|
                                            {'#',' ',' ',' ','*','*','|',' ','|','*','*',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //
                                            {'#',' ',' ',' ','*','*','|',' ','|','*','*',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //
                                            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //
                                            {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};
};

#endif
