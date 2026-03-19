#include <Engine/Render/AnimatedSprite.h>

AnimatedSprite::AnimatedSprite() 
: IAsset(), frameRect(Rectangle{0.0f, 0.0f, 32.0f, 32.0f}),
sprite(Sprite()), totalFrames(0), currentFrame(0), animationDuration(1),
currentAnimationTime(0), frameDuration(0.1f)
{
    this->assetData = AssetData();
    this->assetData.type = AssetType::Animated_Sprite;
    this->assetData.typeData.animatedSprite = AnimatedSpriteData();
}

AnimatedSprite::AnimatedSprite(Vector2 frameSize)
: IAsset(), frameRect(Rectangle{0.0f,0.0f, frameSize.x, frameSize.y}),
sprite(Sprite()), totalFrames(0), currentFrame(0), animationDuration(1),
currentAnimationTime(0), frameDuration(0.1f)
{
    this->assetData = AssetData();
    this->assetData.type = AssetType::Animated_Sprite;
    this->assetData.typeData.animatedSprite = AnimatedSpriteData();
}

//este carga el sprite con su tamaño original
void AnimatedSprite::Load(const char* path, const char* assetName)
{
    if(!IsValidAssetName(assetName)) return;
    this->sprite.Load(path, TextFormat("%i_spriteSheet",assetName));
    this->assetData.typeData.animatedSprite.spriteData=sprite.assetData.typeData.sprite;
    strcpy(this->assetData.strId, assetName);
    strcpy(this->assetData.path, path);
}

//carga el sprite con tamaño escalado, tener en cuenta que como es animacion se debe multiplicar el ancho por el numero de frames
void AnimatedSprite::Load(const char* path, const char* assetName, Vector2 targetSpriteSize)
{
    if(!IsValidAssetName(assetName)) return;
    this->sprite.Load(path, TextFormat("%i_spriteSheet", assetName),(int)targetSpriteSize.x, (int)targetSpriteSize.y);
    this->assetData.typeData.animatedSprite.spriteData=sprite.assetData.typeData.sprite;
    strcpy(this->assetData.strId, assetName);
    strcpy(this->assetData.path, path);
}

//Para evitar errores en escalado se recomienda establecer estas variables antes de hacer la carga del sprite
void AnimatedSprite::SetAnimationFrameRect(Vector2 frameSize)
{
    this->frameRect.width=frameSize.x;
    this->frameRect.height=frameSize.y;

    this->assetData.typeData.animatedSprite.frameSizeX=frameSize.x;
    this->assetData.typeData.animatedSprite.frameSizeY=frameSize.y;
}

void AnimatedSprite::SetAnimationTotalFramesAndDuration(unsigned short total, float duration)
{
    this->totalFrames = total;
    this->animationDuration = duration;
    this->frameDuration = duration/total;

    this->assetData.typeData.animatedSprite.animationDuration=duration;
    this->assetData.typeData.animatedSprite.totalFrames=total;
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