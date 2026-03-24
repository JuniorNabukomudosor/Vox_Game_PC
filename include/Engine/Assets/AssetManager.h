#pragma once
#include <raylib.h>
#include<Engine/Assets/AssetTypesIncludes.h>
#include <memory>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include<iostream>
#include<algorithm>

class AssetTools;

class AssetManager
{
    private:

    std::unordered_map<std::string, std::shared_ptr<IAsset>> assetsByName;
    std::vector<std::shared_ptr<IAsset>> assets;
    std::vector<std::shared_ptr<IAsset>> DeleteTrashCan;

    void AddAssetToLibrary(AssetData data);
    
    public:
    
    AssetManager();
    //Save all assets beign use
    bool SaveAllAssets(const char* targetFilePath);
    //Save one asset
    bool SaveAsset(std::shared_ptr<IAsset> asset, const char* targetFilePath);
    //Load multiple assets from file(file must contain varios assets)
    bool LoadAssetPKG(const char* assetsFilePath);
    //Load One asset from file(file must contain only one asset)
    bool LoadAsset(const char* assetPath);
    std::shared_ptr<IAsset> GetAssetByName(std::string& name);
    void DeleteAssetByName(std::string& name);
    void ReleaseAllAssets();
    void ClearTrashCan(bool destructor);
    ~AssetManager();

    friend class AssetTools;
};
