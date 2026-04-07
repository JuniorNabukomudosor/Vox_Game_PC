#include <Engine/DataEntities/Components/SpriteComponent.h>

SpriteComponent::SpriteComponent(std::shared_ptr<Sprite> sprite)
{
    this->asset = sprite;
}