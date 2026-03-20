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

void AssetTools::RunAssetMenu(AssetManager& manager)
{
    std::string menuStr = R"(
    1- Create Asset
    2- Save Asset
    3- Save All Assets
    4- Load Assets
    5- View Loaded Assets
    0- Exit Asset Menu)";

    std::string createAssetMenu = R"(
    1- Create Simple Sprite
    2- Create Animated Sprite
    0- Cancel
    )";

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