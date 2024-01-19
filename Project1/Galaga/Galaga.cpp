#include <iostream>
#include <ConsoleEngine/ConsoleScreen.h>
#include <ConsoleEngine/EngineDebug.h>
#include <list>
#include <map>
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"

#include "ContentsEnum.h"
#include <ConsoleEngine/EngineCore.h>

int main()
{
    EngineCore EngineCore;

    EngineCore.Init({ 10, 20 });


    {
        // Player* NewObject = new Player();
        Player* NewObject = EngineCore.CreateObject<Player>(GalagaUpdateType::Player, GalagaRenderType::Player);
        NewObject->SetPos({ EngineCore.Screen.GetScreenX() / 2, EngineCore.Screen.GetScreenY() - 2 });
    }

    {
        const int MonsterCount = EngineCore.Screen.GetScreenX() / 2;
        for (int i = 0; i < MonsterCount; i++)
        {
            Monster* NewObject = EngineCore.CreateObject<Monster>(GalagaUpdateType::Monster, GalagaRenderType::Monster);
            NewObject->SetPos({ i, 0 });
            NewObject->MonsterInit();
            NewObject->SetRenderChar('&');
        }
    }

    EngineCore.Start();

}