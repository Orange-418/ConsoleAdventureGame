#ifndef PORTALHANDLER_H
#define PORTALHANDLER_H
#include <string>
#include <vector>

class portalHandler
{
    public:

    std::string handle(int posx, int posy, std::string whichPortal, std::vector<std::vector<char>> map, int direction, std::string level);

    private:
};

#endif // PORTALHANDLER_H
