#ifndef MAP_TUTORIALISLANDCLEARED_H
#define MAP_TUTORIALISLANDCLEARED_H
#include <iostream>
#include <thread>
#include <vector>
#include <tuple>

class map_TutorialIslandCleared
{
    public:

    void moveCursor(int x, int y);
    void hideCursor();
    std::tuple<std::string, int, std::vector<std::string>, int, int> loadMap(int health, std::vector<std::string> inventory, int posX, int posY);

    private:
        std::string mapToLoad;
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

        std::vector<std::vector<char>> map {{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                                            {'O',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //
                                            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //
                                            {'#',' ','@',' ',' ',' ',' ','_',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //  ___
                                            {'#',' ',' ',' ',' ','_','-','_','-','_',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //  |_|
                                            {'#',' ',' ',' ','|',' ','[','O',']',' ','|',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //  |O|
                                            {'#',' ',' ',' ','*','*','|',' ','|','*','*',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //
                                            {'#',' ',' ',' ','*','*','|',' ','|','*','*',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //
                                            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //
                                            {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};
};

#endif // MAP_TUTORIALISLANDCLEARED_H
