#include "npc_Mentor.h"
#include <windows.h>
#include <iostream>

int npc_Mentor::interact()
{
    interacting = true;
    option1[0] = "[How do I leave this island?]";
    option1[1] = "Who are you?";
    option1[2] = "Stop Talking";
    rightSpaces = 2;
    leftSpaces = 0;
    lastPhrase = "Hi, i'm Bob the tutorial master. What can I do ya for?";
    std::vector<std::vector<char>> map {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},       //
                                       {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},       //
                                       {' ',' ','|','|','|','|','|','|',' ',' '},       //    ||||||
                                       {' ','|','|','|','|','|','|','|','|',' '},       //   ||||||||
                                       {'[',']','[',']','[',']','[',']','[',']'},       //  [][][][][]
                                       {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},       //  |        |
                                       {'|',' ',' ','o',' ',' ','o',' ',' ','|'},       //  |  -  -  |
                                       {'|',' ',' ','_','_','_','_',' ',' ','|'},       //  |  ____  |
                                       {'|','_','_','_','_','_','_','_','_','|'},
                                       {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};      //  |________|



    while(interacting)
    {
        system("cls");
        for(int i = 0; i < 10; i++)     //print out the map
        {
            std::cout << map[i][0] << map[i][1] << map[i][2] << map[i][3] << map[i][4] << map[i][5] << map[i][6] << map[i][7] << map[i][8] << map[i][9] << std::endl;
        }


        std::cout << lastPhrase << std::endl;
        std::cout << " " << std::endl;
        std::cout << option1[0] << " " << option1[1] << " " << option1[2] << std::endl;
        if(GetAsyncKeyState(VK_RIGHT))
        {
            switch(rightSpaces)
            {
                case 2:
                    if(leftSpaces > -1)
                    {
                        leftSpaces++;
                    }
                    rightSpaces--;
                    option1[0] = "How do I leave this island?";
                    option1[1] = "[Who are you?]";
                    break;
                case 1:
                    if(leftSpaces > -1)
                    {
                        leftSpaces++;
                    }
                    rightSpaces--;
                    option1[1] = "Who are you?";
                    option1[2] = "[Stop Talking]";
                    break;
                default:
                    break;
            }
        }
        if(GetAsyncKeyState(VK_LEFT))
        {
            switch(leftSpaces)
            {
                case 1:
                    if(rightSpaces > -1)
                    {
                        rightSpaces++;
                    }
                    leftSpaces--;
                    option1[0] = "[How do I leave this island?]";
                    option1[1] = "Who are you?";
                    break;
                case 2:
                    if(rightSpaces > -1)
                    {
                        rightSpaces++;
                    }
                    leftSpaces--;
                    option1[1] = "[Who are you?]";
                    option1[2] = "Stop Talking";
                    break;
                default:
                    break;
            }
        }
        if(GetAsyncKeyState(VK_RETURN))
        {
            switch(rightSpaces)
            {
                case 0:
                    interacting = false;
                    break;
                case 1:
                    lastPhrase = "I am many things. Mainly a tutorial man! Stupid fuck.";
                    break;
                case 2:
                    lastPhrase = "You wanna leave? Fine. Go back outside, and a path should be cleared.";
                    break;
                default:
                break;
            }
        }
    }
    return 1;
}
