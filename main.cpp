#include <iostream>
#include <raylib.h>
#include <GameMaster.h>
#include <Engine/Sprite.h>

int main(int argc, char const *argv[])
{
    InitWindow(800,600, "Game Vox");

    std::string name = "Rock_Paper_Scissors";

    GameMaster master = GameMaster(name);

    master.Frame=0;

    SetTargetFPS(30);

    while (!WindowShouldClose())
    {
        master.Frame +=1;    
        BeginDrawing();
        ClearBackground(BLACK);
        master.Draw();
        EndDrawing();
    }
    master.Exit();
    CloseWindow();
    return 0;
}
