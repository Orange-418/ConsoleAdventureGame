#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

//1 = right
//2 = left
//3 = up
//4 = down

bool checkMove(int posx, int posy, std::vector<std::vector<char>> map, int direction)
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
                default:
                    break;
            }
            break;
        default:
            break;
    }
}




int main()
{
    std::vector<std::vector<char>> map {{'#','#','#','#','#','#','#','#','#','#'},
                                       {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                                       {'#',' ',' ',' ',' ',' ',' ',' ','@','#'},        //     _
                                       {'#',' ',' ',' ','_',' ',' ',' ',' ','#'},        //   _-_-_
                                       {'#',' ','_','-','_','-','_',' ',' ','#'},        //  ||[_]||
                                       {'#','|','|','[','_',']','|','|',' ','#'},        //  **| |**
                                       {'#','*','*','|',' ','|','*','*',' ','#'},        //  **| |**
                                       {'#','*','*','|',' ','|','*','*',' ','#'},
                                       {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                                       {'#','#','#','#','#','#','#','#','#','#'}};

    int level = 1;
    bool running = true;
    int health = 100;
    int posx;
    int posy;
    int direction;

    while(running && level == 1)
    {
        for(int y = 0; y < 10; y++)
        {
            for(int x = 0; x < 10; x++)
            {
                if(map[y][x] == '@'){
                    posx = x;
                    posy = y;
                }
            }
        }

        system("cls");
        std::cout << "Health: " << health << std::endl;

        for(int i = 0; i < 10; i++)
        {
            std::cout << map[i][0] << map[i][1] << map[i][2] << map[i][3] << map[i][4] << map[i][5] << map[i][6] << map[i][7] << map[i][8] << map[i][9] << std::endl;
        }

        if(GetAsyncKeyState(VK_RIGHT))
        {
            direction = 1;
            if(checkMove(posx, posy, map, direction))
            {
                map[posy][posx] = ' ';
                map[posy][posx+1] = '@';
            }

        }

                if(GetAsyncKeyState(VK_LEFT))
        {
            direction = 2;
            if(checkMove(posx, posy, map, direction))
            {
                map[posy][posx] = ' ';
                map[posy][posx-1] = '@';
            }

        }

                if(GetAsyncKeyState(VK_UP))
        {
            direction = 3;
            if(checkMove(posx, posy, map, direction))
            {
                map[posy][posx] = ' ';
                map[posy-1][posx] = '@';
            }

        }

                if(GetAsyncKeyState(VK_DOWN))
        {
            direction = 4;
            if(checkMove(posx, posy, map, direction))
            {
                map[posy][posx] = ' ';
                map[posy+1][posx] = '@';
            }

        }

    }

    return 0;
}
