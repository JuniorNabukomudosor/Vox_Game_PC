#include<Engine/DataEntities/GameObjects/GameObject.h>

GameObject::GameObject(GameObjectData data)
:  gameObjectData(data), attachedBehaviours(std::vector<IBehaviour>())
{}

void GameObject::Start()
{
    for(auto& behaviour : attachedBehaviours)
    {
        behaviour.Start();
    }
}

void GameObject::Update(float deltatime)
{
    for(auto& behaviour : attachedBehaviours)
    {
        behaviour.Update(deltatime);
    }
}

void GameObject::LateUpdate(float deltatime)
{
    for(auto& behaviour : attachedBehaviours)
    {
        behaviour.LateUpdate(deltatime);
    }
}

void GameObject::SetAsset(std::shared_ptr<IAsset> assetPointer)
{
    
}
