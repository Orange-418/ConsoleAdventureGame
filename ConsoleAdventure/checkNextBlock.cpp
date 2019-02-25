#include "checkNextBlock.h"

bool checkNextBlock::checkNext(char nextChar)
{
            switch(nextChar)
            {
                case '#':
                    return false;
                    break;
                case ' ':
                    return true;
                    break;
                case '|':
                    return false;
                    break;
                case '-':
                    return false;
                    break;
                case 'O':
                    return false;
                    break;
                case '[':
                    return false;
                    break;
                case ']':
                    return false;
                    break;
                case '*':
                    return false;
                    break;
                case '_':
                    return false;
                    break;
                case '&':
                    return false;
                    break;
                default:
                    return true;
                    break;
            }
}
