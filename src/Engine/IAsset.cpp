#include <Engine/IAsset.h>

IAsset::IAsset():
type(AssetType::Uknown){}

IAsset::IAsset(AssetType _type)
:type(_type){}