#include "checkPlayerMovement.h"

bool checkPlayerMovement::checkMove(int posx, int posy, std::vector<std::vector<char>> map, int direction)
{
    switch(direction)
    {
    case 1:
            switch(map[posy][posx+1])
            {
                case ' ':
                    return true;
                    break;
                case '#':
                    return false;
                    break;
                case '|':
                    return false;
                    break;
                case '*':
                    return false;
                    break;
                case '[':
                    return false;
                    break;
                case ']':
                    return false;
                    break;
                case '-':
                    return false;
                    break;
                case '_':
                    return false;
                break;
                case 'O':
                    return false;
                    break;
                default:
                    break;
            }
            break;
    case 2:
            switch(map[posy][posx-1])
            {
                case ' ':
                    return true;
                    break;
                case '#':
                    return false;
                    break;
                case '|':
                    return false;
                    break;
                case '*':
                    return false;
                    break;
                case '[':
                    return false;
                    break;
                case ']':
                    return false;
                    break;
                case '-':
                    return false;
                    break;
                case '_':
                    return false;
                    break;
                case 'O':
                    return false;
                    break;
                default:
                    break;
            }
            break;
    case 3:
            switch(map[posy-1][posx])
            {
                case ' ':
                    return true;
                    break;
                case '#':
                    return false;
                    break;
                case '|':
                    return false;
                    break;
                case '*':
                    return false;
                    break;
                case '[':
                    return false;
                    break;
                case ']':
                    return false;
                    break;
                case '-':
                    return false;
                    break;
                case '_':
                    return false;
                    break;
                case 'O':
                    return false;
                    break;
                default:
                    break;
            }
            break;
    case 4:
            switch(map[posy+1][posx])
            {
                case ' ':
                    return true;
                    break;
                case '#':
                    return false;
                    break;
                case '|':
                    return false;
                    break;
                case '*':
                    return false;
                    break;
                case '[':
                    return false;
                    break;
                case ']':
                    return false;
                    break;
                case '-':
                    return false;
                    break;
                case '_':
                    return false;
                    break;
                case 'O':
                    return false;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}
