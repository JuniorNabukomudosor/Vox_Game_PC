#pragma once
#include <raylib.h>
#include <Engine/Assets/IAsset.h>

class Sprite : public IAsset
{
    private:
    Texture2D texture;
    
    public:
    Sprite();
    void Load(const char * path) override;
    void Load(const char * path, int width, int height);
    void Draw(Vector2& position, Color tint);
    void DrawCutted(Vector2& position, Rectangle drawRect, Color tint);
    void Release() override;
};
