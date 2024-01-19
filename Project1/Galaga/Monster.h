#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Monster : public ConsoleObject
{
public:
	void MonsterInit();

protected:
	void Update() override;

private:
	bool IsMoveRight = true;
	int Count = 0;
	int MaxCount = 0;
	int2 Dir = Right;
};

