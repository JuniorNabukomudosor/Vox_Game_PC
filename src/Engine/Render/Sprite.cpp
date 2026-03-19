#include <Engine/Render/Sprite.h>

Sprite::Sprite() : IAsset()
{
    this->assetData = AssetData();
    this->assetData.type=AssetType::Sprite;
    this->assetData.typeData.sprite=SpriteData();
}

void Sprite::Load(const char* path, const char* assetName)
{
    if(!IsValidAssetName(assetName)) return;
    
    if(FileExists(path))
    {
        this->texture= LoadTexture(path);
        //assetdata
        strcpy(this->assetData.path,path);
        strcpy(this->assetData.strId, assetName);
        this->assetData.typeData.sprite.originalSize=true;
        this->assetData.typeData.sprite.height=texture.height;
        this->assetData.typeData.sprite.width=texture.width;
    }else
    {
        TraceLog(LOG_ERROR, TextFormat("No se encontro el recurso %i", path));
    }
    
}

void Sprite::Load(const char * path, const char* assetName, int with, int height)
{
    if(!IsValidAssetName(assetName)) return;
    //esta sobrecarga permite cargar el sprite redimensionandolo a el tamano necesario
    if(FileExists(path))
    {
        Image image = LoadImage(path);
        ImageResizeNN(&image, with,height);

        this->texture = LoadTextureFromImage(image);

        //assetData
        strcpy(this->assetData.path,path);
        strcpy(this->assetData.strId, assetName);
        this->assetData.typeData.sprite.originalSize=false;
        this->assetData.typeData.sprite.height=height;
        this->assetData.typeData.sprite.width=with;

        //libera la imagen de memoria
        UnloadImage(image);
    }else
    {
        TraceLog(LOG_ERROR, TextFormat("No se encontro el recurso %i", path));
    }
}

void Sprite::Draw(Vector2& position, Color tint = WHITE)
{
    DrawTextureV(this->texture, position,tint);
}

void Sprite::DrawCutted(Vector2& position, Rectangle drawRect, Color tint)
{
    DrawTextureRec(this->texture, drawRect, position, tint);
}

void Sprite::Release()
{
    UnloadTexture(this->texture);
}