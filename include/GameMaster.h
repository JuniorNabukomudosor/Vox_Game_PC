#pragma once
#include <Player.h>
#include <string>
#include <Engine/Web/WebManager.h>
//#include<Engine/AssetManager.h>


class GameMaster
{
    private:

    WebManager serverManager;
    //AssetManager assetManager;
    Player P1;
    Player P2;
    

    public:

    unsigned int Frame;
    bool Debug;
    const std::string gameName;

    void Draw();
    void Update();
    void Exit();

    GameMaster(std::string& gameName);
};