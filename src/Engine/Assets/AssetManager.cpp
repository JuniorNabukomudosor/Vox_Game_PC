#include <Engine/Assets/AssetManager.h>

AssetManager::AssetManager()
: assets(std::vector<std::shared_ptr<IAsset>>()),
assetsByName(std::unordered_map<std::string, std::shared_ptr<IAsset>>()),
DeleteTrashCan(std::vector<std::shared_ptr<IAsset>>())
{}

std::shared_ptr<IAsset> AssetManager::GetAssetByName(std::string& name)
{
    auto result = this->assetsByName.find(name);
    if(result != assetsByName.end())
    {
        return result->second;
    }else
    {
        return nullptr;
    }
}

void AssetManager::DeleteAssetByName(std::string& name)
{
    auto pointer = GetAssetByName(name);
    if(pointer != nullptr)
    {
        DeleteTrashCan.push_back(pointer);
    }
}

bool AssetManager::SaveAsset(std::shared_ptr<IAsset> asset, const char* targetFilePath)
{
    std::string fullPath = std::string(targetFilePath) + ".voxasset";

    std::ofstream file(fullPath, std::ios::binary);

    if(!file)
    {
        std::cout << "Error: Could not open file for writing: " << fullPath << std::endl;
        return false;
    }

    file.write(reinterpret_cast<const char *>(&(asset->assetData)), sizeof(asset->assetData));
    std::cout << "Saved asset : " << asset->assetData.strId << std::endl;
    return true;
}

bool AssetManager::SaveAllAssets(const char* targetFilePath)
{

    std::string fullPath = std::string(targetFilePath) + ".voxassetpkg";

    std::ofstream file(fullPath, std::ios::binary);
    
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
        std::cout << "Saved asset : " << asset->assetData.strId << std::endl;
    }
    return true;
}

void AssetManager::AddAssetToLibrary(AssetData data)
{
    std::shared_ptr<IAsset> asset;
    //hacer la instanciacion

    //evitar duplicads por nombre
    auto result = this->assetsByName.find(data.strId);
    if(result != assetsByName.end())
    {
        std::cout << TextFormat("Ya hay un asset con el nombre %s,  saltando...", data.strId) << std::endl;
        return;
    }  

    switch (data.type)
    {
        case AssetType::Sprite:
        {
            Sprite sprite = Sprite();
            //verificar variables pertinentes
            SpriteData spData= data.typeData.sprite;
            //hacer la carga delsprite
            if(spData.originalSize)
            {
                sprite.Load(data.path, data.strId);
            }else
            {
                sprite.Load(data.path, data.strId,spData.width, spData.height);
            }
            //asignar elasset data
            sprite.assetData=data;
            //asignar el puntero
            asset = std::make_shared<Sprite>(sprite);
            break;
        }

        case AssetType::Animated_Sprite:
        {
            AnimatedSprite anSprite = AnimatedSprite();
            AnimatedSpriteData animatedSPData = data.typeData.animatedSprite;
            //animationsetVariables
            anSprite.SetAnimationFrameRect(Vector2{(float)animatedSPData.frameSizeX, (float)animatedSPData.frameSizeY});
            anSprite.SetAnimationTotalFramesAndDuration(animatedSPData.totalFrames, animatedSPData.animationDuration);
            anSprite.Load(data.path, data.strId,Vector2{(float)animatedSPData.frameSizeX*animatedSPData.totalFrames, (float)animatedSPData.frameSizeY});
            //asignar assetdata
            anSprite.assetData=data;
            asset=std::make_shared<AnimatedSprite>(anSprite);
            break;
        }
    } 

    this->assets.push_back(asset);
    this->assetsByName[asset->assetData.strId]=asset;
    std::cout << "Loaded asset " << asset->assetData.strId << " from file" << std::endl;
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

bool AssetManager::LoadAssetPKG(const char* assetsFilePath)
{
    //erificar extension
    if(strstr(assetsFilePath, ".voxassetpkg")==NULL)
    {
        std::cout<<"El archivo no tiene la extension necesaria" << std::endl;
        return false;
    }

    std::ifstream file(assetsFilePath, std::ios::binary);
    
    if(!file)
    {
        std::cout<<"Error abriendo archivo" << std::endl;
        return false;
    }

    //obtener primero el conteo de items guardado en el archivo
    size_t count;
    file.read(reinterpret_cast<char*>(&count), sizeof(size_t));

    //iterar por sobre los assets del paquete
    for(int i = 0; i<count; i++)
    {
        AssetData data;
        file.read(reinterpret_cast<char*>(&data), sizeof(AssetData));
        this->AddAssetToLibrary(data);
    }
    return true;
}

void AssetManager::ReleaseAllAssets()
{
    for(int i= 0; i<assets.size(); i++)
    {
        assetsByName.erase(assets[i]->assetData.strId);
        DeleteTrashCan.push_back(assets[i]);
    }
}

void AssetManager::ClearTrashCan(bool destructor)
{
    //borra de la lista de assets
    for(auto& asset : DeleteTrashCan)
    {
        assets.erase(std::remove(assets.begin(), assets.end(), asset), assets.end());
        if(!destructor)
        {
            //libera los recursos del asset a borrar
            asset->Release();
        }
    }

    DeleteTrashCan.clear();
}

AssetManager::~AssetManager()
{
    this->ReleaseAllAssets();
    this->ClearTrashCan(true);
}