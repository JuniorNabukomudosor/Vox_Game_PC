#pragma once
#include <memory>
#include <Engine/DataEntities/Transform2D.h>
#include <Engine/Assets/IAsset.h>
#include <Engine/Assets/AssetTypeEnum.h>


class GameObject
{
    private:
    std::shared_ptr<IAsset> Asset;
    Transform2D Transform;

    public:
    
    GameObject();
    GameObject(std::shared_ptr<IAsset> assetPointer);
    void SetAsset(std::shared_ptr<IAsset> asset);
    const AssetType GetAssetType() const;
};