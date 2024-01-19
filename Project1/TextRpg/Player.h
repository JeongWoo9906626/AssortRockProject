#pragma once
#include "FightUnit.h"
#include "Weapon.h"

class Player : public FightUnit
{
public:
	Player();

	// �̷� ��쿡 public���� �Ѵ�.
	// ������ ��� �ִ� ��쿡��.
	// ���� �̷���.
	// �����ͷ� �ؾ� �մϴ�.

	// ���� ������� �������� ����
	// �̰� ������ �ؾ�����
	// �����ͷ� �ؾ�����.

	// ���� �����ϰų� �������� ���� ���ɼ��� �ִٸ� => ������
	// ����� ������� �ʾƾ� �ϸ� => ����
	// ������ �����Ҵ��� ����� �ʾұ� ������ 
	Weapon Weapon;

	void FightStart(FightUnit& _Other) override;
	void FightEnd(FightUnit& _Other) override;
	void StatusRenderStart() override;

	void AddExp(int _Value);
	void LevelUpCheck();
	void LevelUp();

protected:
	int GetRandomAtt() override;

private:
	int Level = 1;
	int LevelUpExp = 10;
};

