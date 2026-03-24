#pragma once
#include <Engine/Assets/AssetTypeEnum.h>
#include <Engine/DataEntities/Transform2D.h>

struct GameObjectData
{
    char assetStrID[64];
    const unsigned long long ID;
    Transform2D transform;

};
