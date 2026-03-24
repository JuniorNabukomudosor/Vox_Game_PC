#include <Engine/Assets/IAsset.h>

IAsset::IAsset(): assetData{}
{
    //inicializar en vacio los datos, para evitar errores
    memset(&assetData, 0, sizeof(AssetData));
    uses=0;
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

std::ostream& operator<<(std::ostream& os, const IAsset& f)
{
    os<<"("<<f.assetData.strId<<")"<< " [ type: " << AssetTypeToStr(f.assetData.type) << " path: " << f.assetData.path << "]";
    return os;
}
