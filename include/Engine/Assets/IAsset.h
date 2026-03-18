#pragma once
#include <Engine/Assets/AssetData.h>
#include <Engine/Assets/AssetTypeEnum.h>
#include <cstring>

class IAsset
{
    protected:
    AssetData assetData;
    public:
    IAsset();
    virtual void Load(const char* path) = 0;
    virtual void Release() = 0;
};