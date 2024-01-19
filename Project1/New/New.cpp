#include <iostream>

class Monster
{

};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
    Monster* NewMonster = new Monster();
}