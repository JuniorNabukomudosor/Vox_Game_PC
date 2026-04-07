#pragma once
#include <memory>
#include <Engine/Assets/IAsset.h>
#include <Engine/Assets/AssetTypeEnum.h>
#include <Engine/DataEntities/GameObjects/GameObjectData.h>
#include <Engine/DataEntities/Behaviours/IBehaviour.h>
#include <Engine/DataEntities/Components/Component.h>

class Scene;

class GameObject
{
    private:
    GameObjectData gameObjectData;
    std::vector<IBehaviour> attachedBehaviours;

    public:
    std::vector<std::unique_ptr<Component>> components;
    GameObject(GameObjectData data);
    
    //run at first frame
    void Start();
    //run behaviours
    void Update(float deltatime);
    //run behaviours after de update at same deltatime
    void LateUpdate(float deltatime);
    void SetAsset(std::shared_ptr<IAsset> asset);

    template<typename T>
    T* GetComponent()
    {
        for(auto& c : components)
        {
            if(auto casted = dynamic_cast<T*>(c.get()))
            {
                return casted;
            }
        }
        return nullptr;
    }

    friend class Scene;
};