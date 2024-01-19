#include <iostream>

class FightUnit
{
public:
	virtual int GetAtt()
	{
		return Att;
	}
private:
	int Att = 10;
};

class Monster : public FightUnit
{

};

class Player : public FightUnit
{
protected:
	int GetAtt() override
	{
		return FightUnit::GetAtt() + WeaponAtt;
	}
private:
	int WeaponAtt = 10;
};

void Fight(FightUnit* _Left, FightUnit* _Right)
{
	int PlayerAtt = _Left->GetAtt();
	int MonsterAtt = _Right->GetAtt();
}

int main()
{
	Player NewPlayer;
	Monster NewMonster;

	Fight(&NewPlayer, &NewMonster);
}