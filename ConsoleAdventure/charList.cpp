#include "charList.h"

#define checkMacro(map, x, y, c) if(map[y][x] == c) {return c;}

char charList::check(int x, int y, std::vector<std::vector<char>> map)
{
    checkMacro(map, x, y, '#');
    checkMacro(map, x, y, ' ');
    checkMacro(map, x, y, '@');
}
