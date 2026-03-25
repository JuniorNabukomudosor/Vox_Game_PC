#pragma once
#include <memory>
#include <Engine/Assets/IAsset.h>
#include <Engine/Assets/AssetTypeEnum.h>
#include <Engine/DataEntities/GameObjects/GameObjectData.h>
#include <Engine/DataEntities/Behaviours/IBehaviour.h>

class Scene;

class GameObject
{
    private:
    GameObjectData gameObjectData;
    std::shared_ptr<IAsset> asset;
    std::vector<IBehaviour> attachedBehaviours;

    public:
    
    GameObject(GameObjectData data);
    
    //run at first frame
    void Start();
    //run behaviours
    void Update(float deltatime);
    //run behaviours after de update at same deltatime
    void LateUpdate(float deltatime);
    void SetAsset(std::shared_ptr<IAsset> asset);
    const AssetType GetAssetType() const;

    friend class Scene;
};