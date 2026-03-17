#include <Engine/Render/AnimatedSprite.h>

AnimatedSprite::AnimatedSprite() 
: IAsset(AssetType::Animated_Sprite), frameRect(Rectangle{0.0f, 0.0f, 16.0f, 16.0f}),
sprite(Sprite()), totalFrames(0), currentFrame(0)
{}

AnimatedSprite::AnimatedSprite(Vector2 frameSize)
: IAsset(AssetType::Animated_Sprite), frameRect(Rectangle{0.0f,0.0f, frameSize.x, frameSize.y}),
sprite(Sprite()), totalFrames(0), currentFrame(0)
{}

void AnimatedSprite::Load(const char* path)
{
    this->sprite.Load(path);
}

void AnimatedSprite::SetAnimationFrameRect(Vector2 frameSize)
{
    this->frameRect.width=frameSize.x;
    this->frameRect.height=frameSize.y;
}

void AnimatedSprite::SetAnimationTotalFrames(unsigned short total)
{
    this->totalFrames = total;
}

void AnimatedSprite::Release()
{
    this->sprite.Release();
}

unsigned short AnimatedSprite::DrawAnimation(Vector2& position, Color tint)
{
    frameRect.x=currentFrame*frameRect.width;
    this->sprite.DrawCutted(position, this->frameRect, tint);
    currentFrame+=1;

    if(currentFrame >= totalFrames)
    {
        currentFrame = 0;
    }

    return currentFrame;
}