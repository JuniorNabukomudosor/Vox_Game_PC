#include <Engine/Assets/IAsset.h>

IAsset::IAsset(): assetData{}
{
    //inicializar en vacio los datos, para evitar errores
    memset(&assetData, 0, sizeof(AssetData));
};
