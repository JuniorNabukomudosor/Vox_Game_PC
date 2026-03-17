#include <iostream>
#include <raylib.h>
#include <Engine/GameMaster.h>

#include<Engine/Render/AnimatedSprite.h>

int main(int argc, char const *argv[])
{
    InitWindow(800,600, "Game Vox");

    std::string name = "Rock_Paper_Scissors";

    GameMaster master = GameMaster(name);

    master.Frame=0;

    AnimatedSprite testSp = AnimatedSprite(Vector2{32.0f, 32.0f});
    testSp.Load("../assets/Hand_SpriteAnim.png");
    testSp.SetAnimationTotalFrames(7);

    Vector2 animPos = Vector2{400.0f, 300.0f};

    SetTargetFPS(30);

    while (!WindowShouldClose())
    {
        master.Frame +=1;    
        BeginDrawing();
        ClearBackground(BLACK);
        master.Draw();

        testSp.DrawAnimation(animPos, WHITE);

        EndDrawing();
    }
    master.Exit();

    testSp.Release();

    CloseWindow();
    return 0;
}
