#include <iostream>
#include "Player.h"
#include "Math.h"
#include "ConsoleScreen.h"	
#include "Galaga.h"	
#include "Bullet.h"

int main()
{
	ConsoleScreen NewScreen = ConsoleScreen('*');
	Galaga NewGalaga = Galaga();

	Player NewPlayer = Player();
	Bullet NewBullet = Bullet();
	NewPlayer.SetPos({ ScreenXHalf, ScreenYHalf });
	NewPlayer.SetRenderChar('@');
	NewBullet.SetPos({ 0, 0 });
	NewBullet.SetRenderChar('^');

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