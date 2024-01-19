#include "Player.h"
#include <iostream>
#include <conio.h>

Player::Player()
{
	// ���� �׽�Ʈ �ڵ�
	Weapon.SetName("Steel Sword");
	Weapon.SetAtt(10);
}

void Player::FightStart(FightUnit& _Other)
{

}

void Player::FightEnd(FightUnit& _Other)
{
	int Gold = _Other.GetGold();
	printf_s("�÷��̾ %d ��带 �������ϴ�.\n", Gold);
	AddGold(Gold);

	int DropExp = _Other.GetExp();
	// AddExp(_Other.GetExp()); => Exp = Exp + _Other.GetExp();
	printf_s("�÷��̾ %d ����ġ�� ȹ���߽��ϴ�.\n", DropExp);
	// int Value = _getch();
	AddExp(DropExp);
	// LevelUpExp ���Ͽ� ������
	LevelUpCheck();
	// ������ �ϸ� �ɷ�ġ ��� (�������)
}

void Player::StatusRenderStart()
{
	printf_s("���� %d\n", Level);
	printf_s("����ġ %d / %d\n", GetExp(), LevelUpExp);
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
	printf_s("�÷��̾ �������� �Ͽ����ϴ�.\n");
}

int Player::GetRandomAtt()
{
	CurDamage = FightUnit::GetRandomAtt() + Weapon.GetAtt() + Weapon.GetEquipUp();
	return CurDamage;
}
