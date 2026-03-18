#pragma once
#include <Engine/Assets/AssetTypeEnum.h>

struct SpriteData
{
    //structs para tipos de sprites,  tiene en cuenta si se debe resizear o si se deja tamaño original
    bool originalSize;
    int width;
    int height;
};

struct AnimatedSpriteData
{
    SpriteData spriteData;
    unsigned short totalFrames;
    float animationDuration;
    int frameSizeX;
    int frameSizeY;
};

union AssetTypeData
{
    SpriteData sprite;
    AnimatedSpriteData animatedSprite;
};


struct AssetData
{
    //path al recurso que sera usado por el asset(imagen, audio, etc)
    char path[128];
    //para cada asset el nombre debe ser unico, es un stringId
    char strId[64];
    AssetType type;
    AssetTypeData typeData;
};