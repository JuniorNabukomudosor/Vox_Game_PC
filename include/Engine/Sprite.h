#pragma once
#include <raylib.h>
#include <Engine/IAsset.h>

class Sprite : public IAsset
{
    private:
    Texture2D texture;
    
    public:
    Sprite();
    void Load(const char * path) override;
    void Draw(Vector2& position, Color tint);
    void Release() override;
};
