#include "Monster.h"
#include <iostream>

void Monster::StatusRenderEnd()
{
	printf_s("����ġ : %d\n", GetExp());
}

void Monster::FightStart(FightUnit& _Other)
{
	HpReset();
	RandomGold(1000, 10000);
	RandomExp(1, 10);
}

void Monster::FightEnd(FightUnit& _Other)
{
	// �����ϰ� ����ġ ����
}
