#include <Engine/Assets/AssetManager.h>

AssetManager::AssetManager()
: assets(std::vector<std::shared_ptr<IAsset>>()),
assetsByName(std::unordered_map<std::string, std::shared_ptr<IAsset>>()),
DeleteTrashCan(std::vector<std::shared_ptr<IAsset>>())
{}


bool AssetManager::SaveAsset(std::shared_ptr<IAsset> asset, const char* targetFilePath)
{
    std::string fullPath = std::string(targetFilePath) + ".voxasset";

    std::ofstream file(fullPath, std::ios::binary);

    if(!file)
    {
        return false;
    }

    file.write(reinterpret_cast<const char *>(&(asset->assetData)), sizeof(asset->assetData));
    std::cout<< TextFormat("Saved asset : %i", asset->assetData.strId) << std::endl;
    return true;
}

bool AssetManager::SaveAllAssets(const char* targetFilePath)
{

    std::string fullPath = std::string(targetFilePath) + ".voxasset";

    std::ofstream file(targetFilePath, std::ios::binary);
    
    if(!file)
    {
        return false;
    }

    size_t count = this->assets.size();

    //escribir al principiodel archivo el numero de elementos a guardar
    file.write(reinterpret_cast<const char*>(&count), sizeof(count));

    //ahora para cada elemento del vector guardar el assetData correspondiente
    for(std::shared_ptr<IAsset>& asset : assets)
    {
        file.write(reinterpret_cast<const char*>(&asset->assetData), sizeof(asset->assetData));
        std::cout<< TextFormat("Saved asset : %i", asset->assetData.strId) << std::endl;
    }
    return true;
}