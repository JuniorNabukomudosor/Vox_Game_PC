#include <Engine/Render/AnimatedSprite.h>

AnimatedSprite::AnimatedSprite() 
: IAsset(AssetType::Animated_Sprite), frameRect(Rectangle{0.0f, 0.0f, 32.0f, 32.0f}),
sprite(Sprite()), totalFrames(0), currentFrame(0), animationDuration(1),
currentAnimationTime(0), frameDuration(0.1f) {}

AnimatedSprite::AnimatedSprite(Vector2 frameSize)
: IAsset(AssetType::Animated_Sprite), frameRect(Rectangle{0.0f,0.0f, frameSize.x, frameSize.y}),
sprite(Sprite()), totalFrames(0), currentFrame(0), animationDuration(1),
currentAnimationTime(0), frameDuration(0.1f) {}

//este carga el sprite con su tamaño original
void AnimatedSprite::Load(const char* path)
{
    this->sprite.Load(path);
}

//carga el sprite con tamaño escalado, tener en cuenta que como es animacion se debe multiplicar el ancho por el numero de frames
void AnimatedSprite::Load(const char* path, Vector2 targetSpriteSize)
{
    this->sprite.Load(path, (int)targetSpriteSize.x, (int)targetSpriteSize.y);
}

//Para evitar errores en escalado se recomienda establecer estas variables antes de hacer la carga del sprite
void AnimatedSprite::SetAnimationFrameRect(Vector2 frameSize)
{
    this->frameRect.width=frameSize.x;
    this->frameRect.height=frameSize.y;
}

void AnimatedSprite::SetAnimationTotalFramesAndDuration(unsigned short total, float duration)
{
    this->totalFrames = total;
    this->animationDuration = duration;
    this->frameDuration = duration/total;
}

void AnimatedSprite::Release()
{
    this->sprite.Release();
}

unsigned short AnimatedSprite::DrawAnimation(Vector2& position, float deltaTime, Color tint)
{
    this->currentAnimationTime+=deltaTime;

    float changeTime = frameDuration*(currentFrame+1);

    frameRect.x=currentFrame*frameRect.width;
    this->sprite.DrawCutted(position, this->frameRect, tint);

    if(currentAnimationTime > changeTime)
    {
        currentFrame+=1;
    }
    

    if(currentFrame >= totalFrames)
    {
        currentFrame = 0;
        currentAnimationTime = 0.0f;
    }

    return currentFrame;
}