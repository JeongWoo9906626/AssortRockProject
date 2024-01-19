#include <iostream>

class FightUnit
{
public:
    void Damage(int _Att)
    {
        Hp -= _Att;
    }

    int Att;
    int Hp;
};

// 기능을 물려받기 원하는 클래스 이름
// 형태 = 오른쪽에 : 접근제한지정자 부모 클래스 이름
class Player : public FightUnit
{
//
};

class Monster : FightUnit
{

};

int main()
{
    Player NewPlayer = Player();
    NewPlayer.Att = 20;
}