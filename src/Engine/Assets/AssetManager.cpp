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

void AssetManager::AddAssetToLibrary(AssetData data)
{
    std::shared_ptr<IAsset> asset;
    //hacer la instanciacion

    switch (data.type)
    {
        case AssetType::Sprite:
        
            Sprite sprite = Sprite();
            //verificar variables pertinentes
            SpriteData spData= data.typeData.sprite;
            //hacer la carga delsprite
            if(spData.originalSize)
            {
                sprite.Load(data.path);
            }else
            {
                sprite.Load(data.path, spData.width, spData.height);
            }
            //asignar elasset data
            sprite.assetData=data;
            //asignar el puntero
            asset = std::make_shared<Sprite>(sprite);
            break;

        case AssetType::Animated_Sprite:
            AnimatedSprite anSprite = AnimatedSprite();
            AnimatedSpriteData animatedSPData = data.typeData.animatedSprite;
            //animationsetVariables
            anSprite.SetAnimationFrameRect(Vector2{(float)animatedSPData.frameSizeX, (float)animatedSPData.frameSizeY});
            anSprite.SetAnimationTotalFramesAndDuration(animatedSPData.totalFrames, animatedSPData.animationDuration);
            if(spData.originalSize)
            {
                anSprite.Load(data.path);
            }else
            {
                anSprite.Load(data.path, Vector2{(float)animatedSPData.frameSizeX*animatedSPData.totalFrames, (float)animatedSPData.frameSizeY});
            }
            //asignar assetdata
            anSprite.assetData=data;
            asset=std::make_shared<AnimatedSprite>(anSprite);
            break;
    }

    this->assets.push_back(asset);
    this->assetsByName[data.strId]=asset;
    std::cout<<TextFormat("Loaded asset %i from file", data.strId) << std::endl;
}

bool AssetManager::LoadAsset(const char* assetPath)
{
    //erificar extension
    if(strstr(assetPath, ".voxasset")==NULL)
    {
        std::cout<<"El archivo no tiene la extension necesaria" << std::endl;
        return false;
    }

    std::ifstream file(assetPath, std::ios::binary);
    
    if(!file)
    {
        std::cout<<"Error abriendo archivo" << std::endl;
        return false;
    }

    AssetData data;
    file.read(reinterpret_cast<char*>(&data), sizeof(AssetData));

    this->AddAssetToLibrary(data);
    return true;
}

bool AssetManager::LoadAssetsM(const char* assetsFilePath)
{
    
}

void AssetManager::ReleaseAllAssets()
{
    for(int i= 0; i++ ; i<assets.size())
    {
        assetsByName.erase(assets[i]->assetData.strId);
        DeleteTrashCan.push_back(assets[i]);
    }
}

void AssetManager::ClearTrashCan()
{
    //borra de la lista de assets
    for(auto& asset : DeleteTrashCan)
    {
        assets.erase(std::remove(assets.begin(), assets.end(), asset), assets.end());
        //libera los recursos del asset a borrar
        asset->Release();
    }

    DeleteTrashCan.clear();
}