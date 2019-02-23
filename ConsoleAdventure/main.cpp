#include <string>
#include "map_Tutorial.h"
#include "mapLoader.h"

//1 = right
//2 = left
//3 = up
//4 = down


int main()
{
    mapLoader loadMap;
    loadMap.load("map_Tutorial");
    return 0;
}
