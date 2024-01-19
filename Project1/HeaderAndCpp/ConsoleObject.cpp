#include "ConsoleObject.h"

ConsoleObject::ConsoleObject()
{
}

//ConsoleObject::ConsoleObject(const int2& _StartPos, char _RenderChar)
//{
//}

int2 ConsoleObject::GetPos()
{
	return Pos;
}

char ConsoleObject::GetRenderChar()
{
	return RenderChar;
}

void ConsoleObject::SetPos(const int2& _Pos)
{
	Pos = _Pos;
}

void ConsoleObject::SetRenderChar(const char& _RenderChar)
{
	RenderChar = _RenderChar;
}