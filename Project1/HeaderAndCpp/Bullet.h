#pragma once
#include "ConsoleObject.h"

class Bullet : public ConsoleObject
{
public:
	Bullet();
	Bullet(const int2& _StartPos, char _RenderChar);

	bool& GetIsFireRef();

private:
	bool IsFire = false;
};


