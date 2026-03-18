#pragma once
#include <raylib.h>
#include <Engine/Assets/IAsset.h>
#include <memory>
#include <unordered_map>
#include <vector>
#include <string>
#include <Engine/Assets/AssetTypeEnum.h>

class AssetManager
{
    private:

    std::unordered_map<std::string, std::shared_ptr<IAsset>> assetsByName;
    std::vector<std::shared_ptr<IAsset>> assets;
    std::vector<std::shared_ptr<IAsset>> ToDeleteAssets;
    
    public:
    
    AssetManager();
    void SaveAllAssets(char* targetFilePath);
    void SaveAsset(std::shared_ptr<IAsset> asset, char* targetFilePath);
    void LoadAssets(char* assetConfigFilePath);
    std::shared_ptr<IAsset> GetAssetByName(std::string& name);

    void DeleteAssetByName(std::string& name);
    void ReleaseAllAssets();


    ~AssetManager();
};
