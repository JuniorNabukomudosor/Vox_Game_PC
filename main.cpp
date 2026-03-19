#include <iostream>
#include <raylib.h>
#include <Engine/GameMaster.h>
#include <Engine/Assets/AssetManager.h>

int main(int argc, char const *argv[])
{

    AssetManager assetManager = AssetManager();

    InitWindow(800,600, "Game Vox");

    std::string name = "Rock_Paper_Scissors";
    GameMaster master = GameMaster(name);
    master.Frame=0;

    Vector2 animPos = Vector2{400-64, 300-64};
    AnimatedSprite test;

    /*
    test.SetAnimationFrameRect(Vector2{128.0f,128.0f});
    test.SetAnimationTotalFramesAndDuration(7,1.5f);
    test.Load("../assets/Sprites/Hand_SpriteAnim.png", "Mano_Pixel_Placeholder",Vector2{128.0f*7,128.0f});

    assetManager.SaveAsset(std::make_shared<AnimatedSprite>(test), "../assets/.vox/HandSprite");

    */
    assetManager.LoadAsset("../assets/.vox/HandSprite.voxasset");

    std::string aname = "Mano_Pixel_Placeholder";

    test=*dynamic_cast<AnimatedSprite*>(assetManager.GetAssetByName(aname).get());

    SetTargetFPS(30);

    while (!WindowShouldClose())
    {
        master.Frame +=1;    
        BeginDrawing();
        ClearBackground(BLACK);

        test.DrawAnimation(animPos, GetFrameTime(), WHITE);

        master.Draw();
        EndDrawing();

        if(master.Frame % 1800 == 0)
        {
            //cada minuto se verifica si hay basura en la papelera y se limpia
            assetManager.ClearTrashCan();
        }
    }
    master.Exit();
    CloseWindow();
    return 0;
}
