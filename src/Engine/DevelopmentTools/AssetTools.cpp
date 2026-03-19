#include <Engine/DevelopmentTools/AssetTools.h>

void AssetTools::CreateAssetMenu(AssetManager& manager)
{
    std::string createMenu = R"(
    1- Simple Sprite
    2- Animated Sprite
    )";

    std::cout<<createMenu<<std::endl;
}

void AssetTools::RunAssetMenu(AssetManager& manager)
{
    std::string menuStr = R"(
    1- Create Asset
    2- Save Asset
    3- Save All Assets
    4- Load Assets
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
            case 0:
            {
                shouldExit = true;
                break;
            }
            default:
            {
                std::cout<<menuStr << std::endl;
                break;
            }
        }
    }

    std::cout << "Exited Asset Menu" << std::endl;
}