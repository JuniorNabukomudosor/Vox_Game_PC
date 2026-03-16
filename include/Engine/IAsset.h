#pragma once
#include <Engine/AssetTypeEnum.h>

class IAsset
{
    public:
    const AssetType type;
    IAsset();
    IAsset(AssetType _type);
    virtual void Load(const char* path) = 0;
    virtual void Release() = 0;
};