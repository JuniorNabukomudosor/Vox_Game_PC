#pragma once
#include <memory>


//Component es una clase que se encargar de mantener los assets 
//y metodos genericos para tipos especificos, Sprite, audio, etc con sus respectivos
//metodos para ostrarlos atiempo de ejecucion. ej: Draw(), PlayAudio(), etc

class GameObject;

class Component
{
    
    //cada implementacio ntendra su puntero hacia el IAsset correspondiente asi evitando
    //el cast dinamico en tiempo de ejecucion 
    public:
        virtual ~Component(){}
    
        friend class GameObject;
};