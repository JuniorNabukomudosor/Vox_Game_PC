#pragma once
#include <raylib.h>
#include <Engine/Assets/IAsset.h>
#include <Engine/Render/Sprite.h>

class AnimatedSprite : public IAsset
{
    private:
    Sprite sprite;
    Rectangle frameRect;
    unsigned short totalFrames;
    unsigned short currentFrame;

    public:

    AnimatedSprite();
    AnimatedSprite(Vector2 frameSize);
    void Load(const char* path) override;
    void SetAnimationFrameRect(Vector2 frameSize);
    void SetAnimationTotalFrames(unsigned short total);
    unsigned short DrawAnimation(Vector2& position, Color tint);
    void Release() override;

};