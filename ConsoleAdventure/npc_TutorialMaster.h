#ifndef NPC_TUTORIALMASTER_H
#define NPC_TUTORIALMASTER_H
#include <vector>
#include <string>

class npc_TutorialMaster
{
    public:

    void moveCursor(int x, int y);
    void hideCursor();
    bool interact();

    private:

        std::vector<std::vector<char>> dialog {{' ',' ','_','_','_','_','_','_','_',' ',},
                                               {' ','|',' ',' ',' ',' ',' ',' ',' ','|',},
                                               {' ','|',' ','o',' ',' ',' ','o',' ','|',},
                                               {' ','|',' ',' ','_','_','_',' ',' ','|',},
                                               {' ','|','_','_','_','_','_','_','_','|',},
                                               {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',}};
        bool interacting = true;
        bool returnState = false;

        int sizeX = 10;
        int sizeY = 6;

        std::vector<std::string> optionsDefault {" ", "Who are you?", " ", " ", " ", "How do I leave the island?", " ", " ", " ", "End Conversation", " "};
        std::vector<std::string> options {"[", "Who are you?", "]", " ", " ", "How do I leave the island?", " ", " ", " ", "End Conversation", " "};

        int numRight = 2;
        int numLeft;

        std::string status = "Hi, i'm TutorialMaster Bob. How can I help you?";
};

#endif
