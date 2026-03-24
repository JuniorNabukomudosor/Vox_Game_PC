#include <Engine/DevelopmentTools/AssetTools.h>

void AssetTools::CreateAssetMenu(AssetManager& manager)
{
    std::string createMenu = R"(
    1- Simple Sprite
    2- Animated Sprite
    3- Cancel
    )";

    std::cout<<createMenu<<std::endl;

    int response;
    std::string response_str;
    std::cin>>response;

    switch(response)
    {
        case 1:
        {
            AssetData data;
            data.type = AssetType::Sprite;

            bool original_size;
            std::cout<<"Use sprite original size? y/n"<<std::endl;
            std::cin>>response_str;
            original_size = (response_str == "y");

            std::cout<<"Paste image path"<<std::endl;
            std::string path;
            std::cin.ignore();
            std::getline(std::cin, path);

            int width, heigth;
            std::cout<<"width :";
            std::cin >> width;
            std::cout<<"heigth :";
            std::cin>>heigth;

            std::cout<<"Asset Name: ";
            response_str="";
            std::cin.ignore();
            std::getline(std::cin, response_str);

            if(response_str.size()>=sizeof(data.strId))
            {
                std::cout<<TextFormat("el nombre ha excedido el maximo de lingitud (%i)", sizeof(data.strId)) << std::endl;
                break;
            }

            strcpy(data.strId, response_str.c_str());
            strcpy(data.path, path.c_str());
            data.typeData.sprite = SpriteData();
            data.typeData.sprite.height=heigth;
            data.typeData.sprite.width=width;
            data.typeData.sprite.originalSize=original_size;
            
            manager.AddAssetToLibrary(data);
            break;
        }
        case 2:
        {
            AssetData data;
            data.type = AssetType::Animated_Sprite;

            bool original_size;
            std::cout<<"Use sprite original size? y/n"<<std::endl;
            std::cin>>response_str;
            original_size = strcmp(response_str.c_str(), "y");

            std::cout<<"Paste atlas path"<<std::endl;
            std::string path;
            std::cin.ignore();
            std::getline(std::cin, path);

            int x, y, totalFrames;
            std::cout<<"x frame :";
            std::cin >> x;
            std::cout<<"y frame :";
            std::cin>>y;
            std::cout<<"numberof frames :";
            std::cin>>totalFrames;

            float duration;
            std::cout<<"animation duration :";
            std::cin>>duration;

            std::cout<<"Asset Name: ";
            response_str="";
            std::cin.ignore();
            std::getline(std::cin, response_str);

            if(response_str.size()>=sizeof(data.strId))
            {
                std::cout<<TextFormat("el nombre ha excedido el maximo de lingitud (%i)", sizeof(data.strId)) << std::endl;
                break;
            }

            strcpy(data.strId, response_str.c_str());
            strcpy(data.path, path.c_str());
            data.typeData.animatedSprite = AnimatedSpriteData();
            data.typeData.animatedSprite.animationDuration=duration;
            data.typeData.animatedSprite.frameSizeX=x;
            data.typeData.animatedSprite.frameSizeY=y;
            data.typeData.animatedSprite.totalFrames=totalFrames;
            
            manager.AddAssetToLibrary(data);
            break;
        }
        default:
        {
            std::cout<<"Cancelling"<<std::endl;
            std::cin.ignore();
            break;
        }
    }
}

void AssetTools::SaveAssetMenu(AssetManager& manager)
{
    std::cout<<"Enter Asset Name to save"<<std::endl;
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout<<"Save Path: "<<std::endl;
    std::string savePath;
    std::cin.ignore();
    std::getline(std::cin, savePath);

    auto asset= manager.GetAssetByName(name);

    if(asset!= nullptr)
    {
        if(manager.SaveAsset(asset, savePath.c_str()))
        {
            std::cout << "Asset saved successfully." << std::endl;
        }
        else
        {
            std::cout << "Failed to save asset." << std::endl;
        }
    }else
    {
        std::cout<<"No se encontro el asset"<<std::endl;
    }
}

void AssetTools::SaveAllAssetsMenu(AssetManager& manager)
{
    std::string savePath;
    std::cout << "Save path: ";
    std::cin.ignore();
    std::getline(std::cin, savePath);

    if(manager.SaveAllAssets(savePath.c_str()))
    {
        std::cout<< "Assets packages saved successfully" << std::endl;
    }else
    {
        std::cout<<"Failed to save Assets into package"<< std::endl;
    }
}

void AssetTools::LoadAssetsMenu(AssetManager& manager)
{
    int typeOfLoad;
    std::cout<<"Tipo de carga: \n1- un solo asset \n2- asset package\n3-Cancelar" <<std::endl;
    std::cin>>typeOfLoad;
    std::string filePath;

    switch(typeOfLoad)
    {
        case 1:
        {
            std::cin.ignore();
            std::cout<<".voxasset path: ";
            std::getline(std::cin, filePath);
            std::cout<<"Result:  " << manager.LoadAsset(filePath.c_str());
            break;
        }
        case 2:
        {
            std::cin.ignore();
            std::cout<<".voxassetpkg path: ";
            std::getline(std::cin, filePath);
            std::cout<<"Result:  " << manager.LoadAssetPKG(filePath.c_str());
            break;
        }
        case 3:
        {
            std::cout<<"Cancelling" << std::endl;
            break;
        }
        default: 
        {
            LoadAssetsMenu(manager);
            break;
        }
    }
}

void AssetTools::ShowLoadedAssets(AssetManager& manager)
{
    std::cout << "-------disponible assets--------" << std::endl;
    for(auto& asset : manager.assets)
    {
        std::cout << *asset << std::endl;
    }
    std::cout << "---------------------------------" << "\n\n";
}

void AssetTools::RunAssetMenu(AssetManager& manager)
{
    std::string menuStr = R"(
    1- Create Asset
    2- Save Asset
    3- Save All Assets
    4- Load Assets
    5- View Loaded Assets
    0- Exit Asset Menu)";

    int response = -1;
    bool shouldExit = false;

    while(!shouldExit)
    {
        std::cout << menuStr << std::endl;
        std::cin >> response;
        
        switch(response)
        {
            case 1:
            {
                CreateAssetMenu(manager);
                break;
            }
            case 2:
            {
                SaveAssetMenu(manager);
                break;
            }
            case 3:
            {
                SaveAllAssetsMenu(manager);
                break;
            }
            case 4:
            {
                LoadAssetsMenu(manager);
                break;
            }
            case 5:
            {
                ShowLoadedAssets(manager);
                break;
            }
            case 0:
            {
                shouldExit = true;
                break;
            }
            default:
            {
                std::cout<<menuStr << std::endl;
                //std::cin.ignore();
                break;
            }
        }
    }

    std::cout << "Exited Asset Menu" << std::endl;
}