#include <Engine/GameMaster.h>
#include <raylib.h>

GameMaster::GameMaster(AssetManager& assetManager_, WebManager& webManager_)
: assetManager(assetManager_), serverManager(webManager_),
Debug(true), ActiveAssetMenu(false)
{}

void GameMaster::Start()
{
    std::cout<<"Started Vox Engine"<<std::endl;
}

void GameMaster::Update(float deltaTime)
{
    if(IsKeyDown(KEY_ENTER) && IsKeyDown(KEY_H) && IsKeyDown(KEY_SPACE))
    {
        AssetTools::RunAssetMenu(assetManager);
    }

    if(Frame % 1800 == 0)
    {
        //cada minuto se verifica si hay basura en la papelera y se limpia
        assetManager.ClearTrashCan();
    }
}

void GameMaster::Draw()
{
    if(Debug)
    {
        DrawText(TextFormat("Frame: %i", Frame), 10, 10, 30, WHITE);
    }
}

void GameMaster::Exit()
{}