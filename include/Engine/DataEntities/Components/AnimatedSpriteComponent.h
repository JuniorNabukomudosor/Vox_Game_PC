#pragma once
#include <Engine/DataEntities/Components/Component.h>
#include <Engine/Render/AnimatedSprite.h>

class AnimatedSpriteComponent : public Component
{
    private:
    std::shared_ptr<AnimatedSprite> asset;

    public:
    AnimatedSpriteComponent(std::shared_ptr<AnimatedSprite> asprite);
    void Draw(Vector2 & position, float deltaTime);
};