#include <GameMaster.h>
#include <raylib.h>

GameMaster::GameMaster(std::string& gameName)
: gameName(gameName), serverManager(WebManager()), Debug(true)
{}

void GameMaster::Update()
{

}

void GameMaster::Draw()
{
    if(Debug)
    {
        DrawText(TextFormat("Frame: %i", Frame), 10, 10, 30, WHITE);
    }
}

void GameMaster::Exit()
{
    
}