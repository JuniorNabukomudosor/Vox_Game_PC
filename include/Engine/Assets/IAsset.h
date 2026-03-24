#pragma once
#include <Engine/Assets/AssetData.h>
#include <Engine/Assets/AssetTypeEnum.h>
#include <cstring>
#include <raylib.h>
#include <ostream>

class AssetManager;

class IAsset
{
    protected:
    AssetData assetData;
    //numero de veces que se esta usando el asset, sirve para evitar borrar assets que se esten usando
    unsigned int uses;
    public:
    IAsset();
    virtual void Load(const char* path, const char*assetName) = 0;
    virtual void Release() = 0;
    const virtual AssetType GetAssetType() const;
    bool IsValidAssetName(const char* assetName);

    friend std::ostream& operator<<(std::ostream& os, const IAsset& a);

    friend class AssetManager;
};