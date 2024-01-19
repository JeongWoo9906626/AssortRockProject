#include <iostream>

class FightUnit
{
public:
    virtual void Damage()
    {

    }
};

class Player : public FightUnit
{
public:
    void Damage() override
    {

    }
};

class Test
{

};

int main()
{
    int Size = sizeof(FightUnit);
    int a = 0;
}