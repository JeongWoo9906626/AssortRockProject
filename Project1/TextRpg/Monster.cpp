#include "Monster.h"
#include <iostream>

void Monster::StatusRenderEnd()
{
	printf_s("경험치 : %d\n", GetExp());
}

void Monster::FightStart(FightUnit& _Other)
{
	HpReset();
	RandomGold(1000, 10000);
	RandomExp(1, 10);
}

void Monster::FightEnd(FightUnit& _Other)
{
	// 랜덤하게 경험치 설정
}
