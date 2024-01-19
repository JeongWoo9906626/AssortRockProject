#pragma once
#include <iostream>
#include "Math.h"

const int ScreenX = 20;
const int ScreenY = 12;
const int ScreenXHalf = ScreenX / 2;
const int ScreenYHalf = ScreenY / 2;

class ConsoleScreen
{
public:
	ConsoleScreen(char _BaseChar);
	
	void PrintScreen();
	void ClearScreen();
	void SetPixel(const int2& _Position, char _Char);
	void SetPixel(int _X, int _Y, char _Char);
protected:

private:
	char Arr[ScreenY][ScreenX] = { 0, };
	char BaseCh = ' ';
};

