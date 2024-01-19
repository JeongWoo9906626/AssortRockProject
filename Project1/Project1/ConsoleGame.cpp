// ConsoleGame.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <conio.h>

// ������
// 0. �޸�
// 1. �ڵ� ���� �ȵ�
// 1. �ݺ��� �ڵ� ����
// 3. �޸𸮸� �������� ��� �Ұ��� 
//	  (ȭ���� ũ��, �Ѿ��� ���� ��...)

class int2
{
	// ���� �̷� ������ Ŭ������
	// public���� �ɹ������� �δ� ���Դϴ�.
public:
	int X = 0;
	int Y = 0;

	// ����Ʈ ���Կ�����.
	void operator=(const int2& _Other)
	{
		X = _Other.X;
		Y = _Other.Y;
	}

	int2 operator+(const int2& _Other)
	{
		return { X + _Other.X, Y + _Other.Y };
	}

	void operator+=(const int2& _Other)
	{
		X += _Other.X;
		Y += _Other.Y;
	}
};

const int2 Left = { -1, 0 };
const int2 Right = { 1, 0 };
const int2 Up = { 0, -1 };
const int2 Down = { 0, 1 };

// ���������� ������ ���þ���
// �̸��� ���� �ִٸ� �װ��� ����� �� �ִ�.
const int ScreenX = 20;
const int ScreenY = 12;
const int ScreenXHalf = ScreenX / 2;
const int ScreenYHalf = ScreenY / 2;

class ConsoleScreen
{
public:
	// �����ڸ� ����ٴ°���
	// ���� ���� ������ �������θ� �����ض�.
	ConsoleScreen(char _BaseChar)
	{
		// [*][*][*][*][*][0]
		// [*][*][*][*][*][0]
		// [*][*][*][*][*][0]
		// [*][*][*][*][*][0]
		// [*][*][*][*][*][0]

		BaseCh = _BaseChar;

	}

	void PrintScreen()
	{
		for (int y = 0; y < ScreenY; y++)
		{
			char* Ptr = Arr[y];
			printf_s(Ptr);
			printf_s("\n");
		}
	}

	void ClearScreen()
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

	void SetPixel(const int2& _Position, char _Char)
	{
		SetPixel(_Position.X, _Position.Y, _Char);
	}

	void SetPixel(int _X, int _Y, char _Char)
	{
		Arr[_Y][_X] = _Char;
	}

protected:

private:
	char Arr[ScreenY][ScreenX] = { 0, };
	char BaseCh = ' ';
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
};

class Galaga
{
public:
	void GalagaWallDraw(ConsoleScreen& _Screen)
	{
		// [#][#][#][#][#][#]
		// [0][0][0][0][0][0]
		// [0][0][0][0][0][0]
		// [0][0][0][0][0][0]
		// [0][0][0][0][0][0]

		{
			int2 Start0 = { 0, 0 };
			int2 Start1 = { 0, ScreenY - 1 };
			for (int i = 0; i < ScreenX - 1; i++)
			{
				_Screen.SetPixel(Start0, '#');
				_Screen.SetPixel(Start1, '#');
				Start0 += Right;
				Start1 += Right;
			}
		}

		{
			int2 Start0 = { 0, 0 };
			int2 Start1 = { ScreenX - 2, 0 };
			for (int i = 0; i < ScreenY; i++)
			{
				_Screen.SetPixel(Start0, '#');
				_Screen.SetPixel(Start1, '#');
				Start0 += Down;
				Start1 += Down;
			}
		}

	}

};

class Player
{
public:
	Player()
	{
	}

	Player(const int2& _StartPos, char _RenderChar)
		: Pos(_StartPos), RenderChar(_RenderChar)
	{
	}

	// inline�� �����Ϸ��� �Լ��� �����ϰ�
	// �� ��ġ�� ġȯ���� ������.
	inline int2 GetPos()
	{
		return Pos;
	}

	inline char GetRenderChar()
	{
		return RenderChar;
	}

	void Update()
	{
		// Pos.X += 1;
		// getch�� ���ϰ��� Ȯ���ؼ�

		int Value = _getch();

		switch (Value)
		{
		case 'a':
		case 'A':
		{
			if ((Pos + Left).X != 0)
			{
				Pos += Left;
			}
			break;
		}
		case 'd':
		case 'D':
		{
			if ((Pos + Right).X != (ScreenX - 2))
			{
				Pos += Right;
			}
			break;
		}
		case 'w':
		case 'W':
		{
			if ((Pos + Up).Y != 0)
			{
				Pos += Up;
			}
			break;
		}
		case 's':
		case 'S':
		{
			if ((Pos + Down).Y != (ScreenY - 1))
			{
				Pos += Down;
			}
			break;
		}
		case 'q':
		case 'Q':
		{
			if (nullptr != IsFire)
			{
				*IsFire = true;
			}
			// IsFire = true;
			break;
		}
		default:
			break;
		}
	}

	void SetBulletFire(bool* _IsFire)
	{
		if (nullptr == _IsFire)
		{
			int a = 0;
			return;
		}

		IsFire = _IsFire;
	}

private:
	int2 Pos = { 0, 0 };
	char RenderChar = '@';
	bool* IsFire = nullptr;
};

class Bullet
{
public:
	Bullet(const int2& _StartPos, char _RenderChar)
		: Pos(_StartPos), RenderChar(_RenderChar)
	{
	}

	bool& GetIsFireRef()
	{
		return IsFire;
	}

	inline int2 GetPos()
	{
		return Pos;
	}

	inline char GetRenderChar()
	{
		return RenderChar;
	}

private:
	bool IsFire = false;
	int2 Pos = { 0, 0 };
	char RenderChar = '@';
};

// �Լ��� ���� �޸𸮴� �����Ǿ� �־�� �Ѵ�.
// => exe���Ͽ� �����ִ�. main�Լ��� 100����Ʈ ����Ѵ�.
// �ѹ� �������� �ǰ��� ����� �ٲ�� ����
int main()
{
	// ���� 1
	// ȭ�� �ܰ��� ������ ä����
	// �÷��̾ �� �ٱ����� �������� ������.
	// [#][#][#][#][#][0]
	// [#][*][*][*][#][0]
	// [#][*][@][*][#][0]
	// [#][*][*][*][#][0]
	// [#][#][#][#][#][0]

	// ���� 2
	// �÷��̾ Ű�� ������
	// [#][#][#][#][#][0]
	// [#][I][*][*][#][0]
	// [#][*][@][*][#][0]
	// [#][*][*][*][#][0]
	// [#][#][#][#][#][0]


	// ������ ���� �����.
	ConsoleScreen NewScreen = ConsoleScreen('*');
	Galaga NewGalaga = Galaga();

	Player NewPlayer = Player({ ScreenXHalf, ScreenYHalf }, '@');
	Bullet NewBullet = Bullet({ 0,0 }, '^');

	bool& Ref = NewBullet.GetIsFireRef();
	NewPlayer.SetBulletFire(&Ref);

	while (true)
	{
		NewScreen.ClearScreen();
		NewGalaga.GalagaWallDraw(NewScreen);

		int2 Index = NewPlayer.GetPos();
		char Ch = NewPlayer.GetRenderChar();

		NewScreen.SetPixel(Index, Ch);

		if (true == NewBullet.GetIsFireRef())
		{
			NewScreen.SetPixel(NewBullet.GetPos(), NewBullet.GetRenderChar());
		}

		NewScreen.PrintScreen();
		NewPlayer.Update();
	}
}
