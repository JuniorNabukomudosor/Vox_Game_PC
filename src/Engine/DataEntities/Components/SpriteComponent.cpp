#include <Engine/DataEntities/Components/SpriteComponent.h>

SpriteComponent::SpriteComponent(std::shared_ptr<Sprite> sprite)
{
    this->asset = sprite;
}

void SpriteComponent::Draw(Vector2& position)
{
    this->asset->Draw(position, WHITE);
}