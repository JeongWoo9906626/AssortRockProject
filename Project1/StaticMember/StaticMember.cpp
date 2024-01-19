#include <iostream>

class Monster
{
public:
    Monster()
    {
        ++MonsterCount;
    }

    static int GetMonsterCount()
    {
        return MonsterCount;
    }

private:
    static int MonsterCount;
};

int Monster::MonsterCount = 0;

class Player
{
public:
    bool IsEnd()
    {
        if (0 >= Monster::GetMonsterCount())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    
}