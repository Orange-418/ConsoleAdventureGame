#ifndef NPC_MENTOR_H
#define NPC_MENTOR_H
#include <string>
#include <vector>

class npc_Mentor
{
    public:

        int interact();

    private:

    std::string lastPhrase;
    int rightSpaces;
    int leftSpaces;
    bool interacting;

    std::vector<std::string> option1 {"","",""};
    //vector<std::string> option2;
   // vector<std::string> option3;

};

#endif // NPC_MENTOR_H
