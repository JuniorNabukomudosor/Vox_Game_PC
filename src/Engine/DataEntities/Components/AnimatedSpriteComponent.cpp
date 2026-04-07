#include <Engine/DataEntities/Components/AnimatedSpriteComponent.h>

AnimatedSpriteComponent::AnimatedSpriteComponent(std::shared_ptr<AnimatedSprite> asprite)
{
    this->asset = asprite;
}

void AnimatedSpriteComponent::Draw(Vector2& position, float deltaTime)
{
    this->asset->DrawAnimation(position, deltaTime, WHITE);
}