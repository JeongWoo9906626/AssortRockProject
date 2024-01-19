#include "Monster.h"

#include <ConsoleEngine/EngineCore.h>

#include "ContentsEnum.h"

void Monster::MonsterInit()
{
	MaxCount = GetCore()->Screen.GetScreenX() / 2;
	Count = MaxCount;
}

void Monster::Update()
{
	if (0 >= Count)
	{
		AddPos(Down);
		Dir.X *= -1;
		Count = MaxCount;
	}
	else
	{
		AddPos(Dir);
		--Count;
	}

	if (GetPos().Y == GetCore()->Screen.GetScreenY())
	{
		GetCore()->EngineEnd();
	}

	ConsoleObject* CollisionObject = Collision(GalagaUpdateType::Bullet);

	if (nullptr != CollisionObject)
	{
		Destroy();
		CollisionObject->Destroy();
	}
}