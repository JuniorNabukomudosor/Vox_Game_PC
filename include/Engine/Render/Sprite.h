#pragma once
#include <Engine/Assets/IAsset.h>

class AnimatedSprite;

class Sprite : public IAsset
{
    private:
    Texture2D texture;
    
    public:
    Sprite();
    void Load(const char * path, const char* assetName) override;
    void Load(const char * path, const char* assetName, int width, int height);
    void Draw(Vector2& position, Color tint);
    void DrawCutted(Vector2& position, Rectangle drawRect, Color tint);
    void Release() override;

    friend class AnimatedSprite;
};
