#pragma once
#include <raylib.h>
#include <Engine/IAsset.h>
#include <memory>
#include <unordered_map>
#include <vector>
#include <string>
#include <Engine/AssetTypeEnum.h>

class AssetManager
{
    private:

    std::unordered_map<std::string, std::shared_ptr<IAsset>> assetsByName;
    std::vector<std::shared_ptr<IAsset>> assets;
    
    public:
    
    AssetManager();
    
    bool LoadAssetsFromFolderRecursive(char* baseFolder, AssetType type);
    bool LoadEspecificAsset(char* path, AssetType type);
    
    std::shared_ptr<IAsset> GetAssetByName(std::string& name);

    bool ReleaseAssets();

    ~AssetManager();
};
