#pragma once
#include <Engine/Assets/AssetManager.h>

class AssetTools
{
    private:
    static void CreateAssetMenu(AssetManager& manager);
    static void SaveAssetMenu(AssetManager& manager);
    static void SaveAllAssetsMenu(AssetManager& manager);
    static void LoadAssetsMenu(AssetManager& manager);
    static void ShowLoadedAssets(AssetManager& manager);

    public:
    //Menu para la carga de assets,  detiene el loop del juego, mientras se ve el programa en la consola
    static void RunAssetMenu(AssetManager& manager);
};