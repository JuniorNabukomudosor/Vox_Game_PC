#include <Engine/Assets/IAsset.h>

IAsset::IAsset(): assetData{}
{
    //inicializar en vacio los datos, para evitar errores
    memset(&assetData, 0, sizeof(AssetData));
}

const AssetType IAsset::GetAssetType() const
{
    return this->assetData.type;
}

bool IAsset::IsValidAssetName(const char* assetName)
{
    if(std::strlen(assetName)>63)
    {
        TraceLog(LOG_ERROR, TextFormat("El nombre asignado es muy largo, debe ser de 63 caracteres o menos"));
        return false;
    }

    return true;
}
