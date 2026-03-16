#include <Engine/Sprite.h>

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

void Sprite::Release()
{
    UnloadTexture(this->texture);
}