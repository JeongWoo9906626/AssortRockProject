#include "ConsoleScreen.h"

ConsoleScreen::ConsoleScreen(char _BaseChar)
{
	// [*][*][*][*][*][0]
	// [*][*][*][*][*][0]
	// [*][*][*][*][*][0]
	// [*][*][*][*][*][0]
	// [*][*][*][*][*][0]

	BaseCh = _BaseChar;

}

void ConsoleScreen::PrintScreen()
{
	for (int y = 0; y < ScreenY; y++)
	{
		char* Ptr = Arr[y];
		printf_s(Ptr);
		printf_s("\n");
	}
}

void ConsoleScreen::ClearScreen()
{
	system("cls");

	for (int y = 0; y < ScreenY; y++)
	{
		for (int x = 0; x < ScreenX - 1; x++)
		{
			Arr[y][x] = BaseCh;
		}
	}
}

void ConsoleScreen::SetPixel(const int2& _Position, char _Char)
{
	SetPixel(_Position.X, _Position.Y, _Char);
}

void ConsoleScreen::SetPixel(int _X, int _Y, char _Char)
{
	Arr[_Y][_X] = _Char;
}