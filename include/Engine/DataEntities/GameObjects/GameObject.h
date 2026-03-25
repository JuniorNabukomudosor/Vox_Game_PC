#pragma once
#include <memory>
#include <Engine/Assets/IAsset.h>
#include <Engine/Assets/AssetTypeEnum.h>
#include <Engine/DataEntities/GameObjects/GameObjectData.h>

class GameObject
{
    private:
    GameObjectData gameObjectData;

    public:
    
    GameObject();
    GameObject(std::shared_ptr<IAsset> assetPointer);
    void Start();
    void Update();
    void SetAsset(std::shared_ptr<IAsset> asset);
    const AssetType GetAssetType() const;
};