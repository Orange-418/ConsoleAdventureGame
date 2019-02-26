#include "npc_TutorialMaster.h"
#include "windows.h"
#include <iostream>
#include <thread>

void npc_TutorialMaster::moveCursor(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void npc_TutorialMaster::hideCursor()
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

bool npc_TutorialMaster::interact()
{
    hideCursor();
    system("cls");
    Sleep(100);
    options = optionsDefault;   //reset options to default from previous interactions
    options[0] = "[";
    options[2] = "]";
    numRight = 2;
    status = "Hi, i'm TutorialMaster Bob. How can I help you?";

    while(interacting)
    {
        numLeft = 2 - numRight;

        for(int x = 0; x < sizeX; x++)      //prints out the map
        {
            for(int y = 0; y < sizeY; y++)
            {
                moveCursor(x, y);
                std::cout << dialog[y][x];
                std::cout<<std::endl;
            }
        }
        std::cout<<std::endl;
        std::cout << status;

        Sleep(75);

        std::cout<<std::endl;
        std::cout<<std::endl;

        for(int i = 0; i < options.size(); i++)
        {
        std::cout << options[i];
        }

        if(GetAsyncKeyState(VK_RIGHT))
        {
            switch(numRight)
            {
                case 1:
                    numRight--;
                    options = optionsDefault;
                    options[8] = "[";
                    options[10] = "]";
                    break;
                case 2:
                    numRight--;
                    options = optionsDefault;
                    options[4] = "[";
                    options[6] = "]";
                    break;
                default:
                    break;
            }
        }

        if(GetAsyncKeyState(VK_LEFT))
        {
            switch(numLeft)
            {
                case 1:
                    numRight++;
                    options = optionsDefault;
                    options[0] = "[";
                    options[2] = "]";
                    break;
                case 2:
                    numRight++;
                    options = optionsDefault;
                    options[4] = "[";
                    options[6] = "]";
                    break;
                default:
                    break;
            }
        }

        if(GetAsyncKeyState(VK_RETURN))
        {
            system("cls");
            switch(numRight)
            {
                case 1:
                    status = "Leave? Ok fine, go back outside and there should be a path cleared.";
                    returnState = true;
                    break;
                case 2:
                    status = "I just said! I'm TutorialMaster Bob!";
                    break;
                default:
                    return returnState;
                    break;
            }
        }

    }


}
