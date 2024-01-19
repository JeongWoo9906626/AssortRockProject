#include <iostream>

// Declaration (선언)
void FightDamage(int* _Hp, int _Att);

class Monster
{
public:
    int Hp;

    void Damage(int _Att)
    {
        FightDamage(&Hp, _Att);
        
    }
};

// Declaration (구현)
//void FightDamage(int* _Hp, int _Att)
//{
//    *_Hp -= _Att;
//}

class Player
{
public:
    int Hp;

    void Damage(int _Att)
    {
        FightDamage(&Hp, _Att);
    }
    void TestPlayerRender();
};

void Player::TestPlayerRender()
{

}

int main()
{
    Monster NewMonster = Monster();
    Player NewPlayer = Player();
}
