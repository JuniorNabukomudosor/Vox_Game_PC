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
    float currentAnimationTime;
    float frameDuration;
    float animationDuration;


    public:

    AnimatedSprite();
    AnimatedSprite(Vector2 frameSize);
    void Load(const char* path) override;
    void Load(const char* path, Vector2 targetSpriteSize);
    void SetAnimationFrameRect(Vector2 frameSize);
    void SetAnimationTotalFramesAndDuration(unsigned short total, float duration);
    unsigned short DrawAnimation(Vector2& position, float deltaTime, Color tint);
    void Release() override;

};