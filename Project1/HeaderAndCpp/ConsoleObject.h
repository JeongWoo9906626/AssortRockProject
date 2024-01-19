#pragma once
#include "Math.h"

// �ڽĵ��� ���������� �������� ����� ���� ��
class ConsoleObject
{
public:
	ConsoleObject();
	//ConsoleObject(const int2& _StartPos, char _RenderChar);

	int2 GetPos();
	char GetRenderChar();

	void SetPos(const int2& _Pos);
	void SetRenderChar(const char& _RenderChar);

protected:
	int2 Pos = { 0, 0 };
	char RenderChar = '@';

private:
	
};

