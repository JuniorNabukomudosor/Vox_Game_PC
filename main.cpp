#include <iostream>
#include <raylib.h>
#include <Engine/GameMaster.h>
#include <Engine/Assets/AssetManager.h>

int main(int argc, char const *argv[])
{

    AssetManager assetManager = AssetManager();
    WebManager webManager = WebManager();

    InitWindow(800,600, "Game Vox");
    
    GameMaster master = GameMaster(assetManager, webManager);
    master.Frame=0;

    SetTargetFPS(30);

    master.Start();

    while (!WindowShouldClose())
    {
        master.Frame +=1;
        //hacer el update antes de dibujar
        master.Update(GetFrameTime()); 
        BeginDrawing();
        ClearBackground(BLACK);
        master.Draw();
        EndDrawing();
    }
    master.Exit();
    CloseWindow();
    return 0;
}
