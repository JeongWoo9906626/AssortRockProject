#include "Player.h"
#include <iostream>
#include <conio.h>

Player::Player()
{
	// 지금 테스트 코드
	Weapon.SetName("Steel Sword");
	Weapon.SetAtt(10);
}

void Player::FightStart(FightUnit& _Other)
{

}

void Player::FightEnd(FightUnit& _Other)
{
	int Gold = _Other.GetGold();
	printf_s("플레이어가 %d 골드를 벌었습니다.\n", Gold);
	AddGold(Gold);

	int DropExp = _Other.GetExp();
	// AddExp(_Other.GetExp()); => Exp = Exp + _Other.GetExp();
	printf_s("플레이어가 %d 경험치를 획득했습니다.\n", DropExp);
	// int Value = _getch();
	AddExp(DropExp);
	// LevelUpExp 비교하여 레벨업
	LevelUpCheck();
	// 레벨업 하면 능력치 상승 (마음대로)
}

void Player::StatusRenderStart()
{
	printf_s("레벨 %d\n", Level);
	printf_s("경험치 %d / %d\n", GetExp(), LevelUpExp);
}

void Player::AddExp(int _Value)
{
	Exp += _Value;
}

void Player::LevelUpCheck()
{
	while (GetExp() >= LevelUpExp)
	{
		LevelUp();
	}
}

void Player::LevelUp()
{
	++Level;
	MaxAtt += 5;
	MinAtt += 5;
	MaxHp += 20;
	HpReset();
	Exp -= LevelUpExp;
	LevelUpExp += 10;
	printf_s("플레이어가 레벨업을 하였습니다.\n");
}

int Player::GetRandomAtt()
{
	CurDamage = FightUnit::GetRandomAtt() + Weapon.GetAtt() + Weapon.GetEquipUp();
	return CurDamage;
}
