#pragma once
#include <Engine/Assets/AssetData.h>
#include <Engine/Assets/AssetTypeEnum.h>
#include <cstring>
#include <raylib.h>

class AssetManager;

class IAsset
{
    protected:
    AssetData assetData;
    public:
    IAsset();
    virtual void Load(const char* path, const char*assetName) = 0;
    virtual void Release() = 0;
    const virtual AssetType GetAssetType() const;
    bool IsValidAssetName(const char* assetName);

    friend class AssetManager;
};