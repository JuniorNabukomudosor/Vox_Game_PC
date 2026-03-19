#include<Engine/DataEntities/GameObject.h>

GameObject::GameObject()
{}

GameObject::GameObject(std::shared_ptr<IAsset> assetPointer)
:Asset(assetPointer){}

void GameObject::SetAsset(std::shared_ptr<IAsset> asset)
{
    this->Asset = asset;
}

const AssetType GameObject::GetAssetType() const
{
    return this->Asset->GetAssetType();
}