#include <Engine/Render/Sprite.h>

Sprite::Sprite() : IAsset()
{}

void Sprite::Load(const char* path)
{
    if(FileExists(path))
    {
        this->texture= LoadTexture(path);
    }else
    {
        TraceLog(LOG_ERROR, TextFormat("No se encontro el recurso %i", path));
    }
    
}

void Sprite::Load(const char * path, int with, int height)
{
    //esta sobrecarga permite cargar el sprite redimensionandolo a el tamano necesario
    if(FileExists(path))
    {
        Image image = LoadImage(path);
        ImageResizeNN(&image, with,height);

        this->texture = LoadTextureFromImage(image);

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