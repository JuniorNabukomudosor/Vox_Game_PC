#pragma once
#include <string>
#include <Engine/DataEntities/Player.h>
#include <Engine/Assets/AssetManager.h>
#include <Engine/Web/WebManager.h>
#include <Engine/DevelopmentTools/AssetTools.h>


class GameMaster
{
    private:

    AssetManager& assetManager;
    WebManager& serverManager;
    Player P1;
    Player P2;

    public:

    unsigned int Frame;
    bool Debug;
    bool ActiveAssetMenu;

    GameMaster(AssetManager& assetManager_, WebManager& webManager_);

    void Draw();
    void Start();
    void Update(float deltaTime);
    void Exit();

};