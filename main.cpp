#include <iostream>
#include <raylib.h>
#include <GameMaster.h>
#include <Engine/Sprite.h>

int main(int argc, char const *argv[])
{
    InitWindow(800,600, "Game Vox");

    std::string name = "Rock_Paper_Scissors";

    GameMaster master = GameMaster(name);

    Sprite testSp;

    testSp.Load("assets/test.png");

    master.Frame=0;

    Vector2 vec = {0.0, 50.0};

    float sum = 1;

    SetTargetFPS(30);

    while (!WindowShouldClose())
    {
        master.Frame +=1;
        vec.x += sum;    

        if (vec.x >= 200.f || vec.x <0)
        {
            sum= sum*-1.0f;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText(TextFormat("x: %.0f",vec.x), 0, 50, 15, WHITE);
        master.Draw();
        testSp.Draw(vec, WHITE);
        EndDrawing();
    }
    master.Exit();
    testSp.Release();
    CloseWindow();
    return 0;
}
