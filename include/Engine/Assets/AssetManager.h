#pragma once
#include <raylib.h>
#include <Engine/Assets/IAsset.h>
#include <memory>
#include <unordered_map>
#include <vector>
#include <string>
#include <Engine/Assets/AssetTypeEnum.h>
#include <fstream>
#include<iostream>

class AssetManager
{
    private:

    std::unordered_map<std::string, std::shared_ptr<IAsset>> assetsByName;
    std::vector<std::shared_ptr<IAsset>> assets;
    std::vector<std::shared_ptr<IAsset>> DeleteTrashCan;
    
    public:
    
    AssetManager();
    bool SaveAllAssets(const char* targetFilePath);
    bool SaveAsset(std::shared_ptr<IAsset> asset, const char* targetFilePath);
    bool LoadAssets(const char* assetConfigFilePath);
    std::shared_ptr<IAsset> GetAssetByName(std::string& name);
    void DeleteAssetByName(std::string& name);
    void ReleaseAllAssets();
    void ClearTrashCan();
    ~AssetManager();
};
