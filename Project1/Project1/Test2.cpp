//#include <iostream>
//#include <conio.h>
//
//class int2
//{
//public:
//	int X = 0;
//	int Y = 0;
//
//	void operator=(const int2& _Other)
//	{
//		X = _Other.X;
//		Y = _Other.Y;
//	}
//
//	int2 operator+(const int2& _Other)
//	{
//		return { X + _Other.X, Y + _Other.Y };
//	}
//
//	void operator+= (const int2 & _Other)
//	{
//		X += _Other.X;
//		Y += _Other.Y;
//	}
//};
//
//const int2 Left = { -1, 0 };
//const int2 Right = { 1, 0 };
//const int2 Up = { 0, -1 };
//const int2 Down = { 0, 1 };
//
//const int ScreenX = 12;
//const int ScreenY = 10;
//const int ScreenXHalf = ScreenX / 2;
//const int ScreenYHalf = ScreenY / 2;
//
//class ConsoleScreen
//{
//public:
//	ConsoleScreen(char _BaseCh)
//	{
//		BaseCh = _BaseCh;
//	}
//
//	void PrintScreen()
//	{
//		for (int y = 0; y < ScreenY; y++)
//		{
//			char* Ptr = Arr[y];
//			printf_s(Ptr);
//			printf_s("\n");
//		}
//	}
//
//	void ClearScreen()
//	{
//		system("cls");
//
//		for (int y = 0; y < ScreenY; y++)
//		{
//			for (int x = 0; x < ScreenX - 1; x++)
//			{
//				Arr[y][x] = BaseCh;
//			}
//		}
//	}
//
//	void SetPixel(const int2& _Position, char _Char)
//	{
//		SetPixel(_Position.X, _Position.Y, _Char);
//	}
//
//	void SetPixel(int _X, int _Y, char _Char)
//	{
//		Arr[_X][_Y] = _Char;
//	}
//
//protected:
//
//private:
//	char Arr[ScreenY][ScreenX] = { 0, };
//	char BaseCh = ' ';
//};
//
//class Galaga
//{
//public:
//	void GalagaWallDraw(ConsoleScreen& _Screen)
//	{
//		{
//			int2 Start0 = { 0, 0 };
//			int2 Start1 = { 0, ScreenY - 1 };
//
//			// Y -> 방향 그리기
//			for (int i = 0; i < ScreenX - 1; i++)
//			{
//				_Screen.SetPixel(Start0, '#');
//				_Screen.SetPixel(Start1, '#');
//
//				Start0 += Right;
//				Start1 += Right;
//			}
//		}
//
//		{
//			int2 Start0 = { 0, 0 };
//			int2 Start1 = { ScreenX - 2, 0 };
//
//			// X (아래) 방향 그리기
//			for (int i = 0; i < ScreenY; i++)
//			{
//				_Screen.SetPixel(Start0, '#');
//				_Screen.SetPixel(Start1, '#');
//
//				Start0 += Down;
//				Start1 += Down;
//			}
//		}
//	}
//};
//
//class Player
//{
//public:
//	Player()
//	{
//	}
//
//	Player(const int2& _StartPos, char _RenderChar)
//		: Pos(_StartPos), RenderChar(_RenderChar)
//	{
//	}
//
//	inline int2 GetPos()
//	{
//		return Pos;
//	}
//
//	inline char GetRenderChar()
//	{
//		return RenderChar;
//	}
//
//	void Update()
//	{
//		int Value = _getch();
//
//		switch (Value)
//		{
//		case 'a':
//		case 'A':
//		{
//			if ((Pos + Left).X != 0)
//			{
//				Pos += Left;
//			}
//			break;
//		}
//		case 'd':
//		case 'D':
//		{
//			if ((Pos + Right).X != (ScreenX - 3))
//			{
//				Pos += Right;
//			}
//			break;
//		}
//		case 'w':
//		case 'W':
//		{
//			if ((Pos + Up).Y != 0)
//			{
//				Pos += Up;
//			}
//			break;
//		}
//		case 's':
//		case 'S':
//		{
//			if ((Pos + Down).Y != (ScreenY - 0))
//			{
//				Pos += Down;
//			}
//			break;
//		}
//		case 'q':
//		case 'Q':
//		{
//			if (nullptr != IsFire)
//			{
//				*IsFire = true;
//			}
//			break;
//		}
//		default:
//			break;
//		}
//	}
//
//	void SetBulletFire(bool* _IsFire)
//	{
//		if (nullptr == _IsFire)
//		{
//			return;
//		}
//
//		IsFire = _IsFire;
//	}
//
//protected:
//
//private:
//	int2 Pos = { 0, 0 };
//	char RenderChar = '@';
//	bool* IsFire = nullptr;
//};
//
//class Bullet
//{
//public:
//	Bullet(const int2& _StartPos, char _RenderChar)
//		: Pos(_StartPos), RenderChar(_RenderChar)
//	{
//	}
//
//	bool& GetFireRef()
//	{
//		return IsFire;
//	}
//
//	inline int2 GetPos()
//	{
//		return Pos;
//	}
//
//	inline char GetRenderChar()
//	{
//		return RenderChar;
//	}
//
//protected:
//
//private:
//	int2 Pos = { 0, 0 };
//	char RenderChar = '@';
//	bool IsFire = false;
//};
//
//int main()
//{
//	ConsoleScreen NewScreen = ConsoleScreen('*');
//	Galaga NewGalaga = Galaga();
//
//	Player NewPlayer = Player({ ScreenXHalf, ScreenYHalf }, '@');
//	Bullet NewBullet = Bullet({ NewPlayer.GetPos().X, NewPlayer.GetPos().Y - 1 }, '^');
//
//	bool& Ref = NewBullet.GetFireRef();
//	NewPlayer.SetBulletFire(&Ref);
//
//	while (true)
//	{
//		NewScreen.ClearScreen();
//		NewGalaga.GalagaWallDraw(NewScreen);
//
//		int2 Index = NewPlayer.GetPos();
//		char Ch = NewPlayer.GetRenderChar();
//
//		NewScreen.SetPixel(Index, Ch);
//
//		if (true == NewBullet.GetFireRef())
//		{
//			NewScreen.SetPixel(NewBullet.GetPos(), NewBullet.GetRenderChar());
//		}
//
//		NewScreen.PrintScreen();
//		NewPlayer.Update();
//	}
//
//}