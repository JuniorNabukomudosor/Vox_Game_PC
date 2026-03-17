#pragma once
#include <memory>
#include <Engine/Transform2D.h>
#include <Engine/IAsset.h>
#include <Engine/AssetTypeEnum.h>


class GameObject
{
    private:

    std::shared_ptr<IAsset> Asset;
    Transform2D Transform;

    public:

    GameObject();
    GameObject(std::shared_ptr<IAsset> assetPointer);

    void SetAsset(std::shared_ptr<IAsset> asset);
    void ClearAsset();
    const AssetType GetAssetType() const;

    ~GameObject();
};