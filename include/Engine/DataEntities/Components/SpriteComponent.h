#pragma once
#include <Engine/DataEntities/Components/Component.h>
#include <Engine/Render/Sprite.h>

class GameObject;

class SpriteComponent : public Component
{
    private:
    std::shared_ptr<Sprite> asset;

    public:
    SpriteComponent(std::shared_ptr<Sprite> sprite);
    void Draw(Vector2& position);

    friend class GameObject;
};