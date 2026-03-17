#include <Engine/Render/Sprite.h>

Sprite::Sprite() : IAsset(AssetType::Sprite)
{}

void Sprite::Load(const char* path)
{
    this->texture= LoadTexture(path);
}

void Sprite::Draw(Vector2& position, Color tint = WHITE)
{
    DrawTextureV(this->texture, position,tint);
}

void Sprite::DrawCutted(Vector2& position, Rectangle drawRect, Color tint)
{
    DrawTextureRec(this->texture, drawRect, position, tint);
}

void Sprite::Release()
{
    UnloadTexture(this->texture);
}