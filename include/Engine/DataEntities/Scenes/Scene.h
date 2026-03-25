#pragma once
#include <Engine/DataEntities/GameObjects/GameObject.h>
#include <vector>
#include <unordered_map>
#include <string>
#include <Engine/Assets/AssetTypeEnum.h>
#include <Engine/DataEntities/Scenes/SceneData.h>


class Scene
{
    private:

    SceneData data;

    std::vector<char[64]> necessaryAssetsStrIds;
    
    std::vector<GameObject> gameObjects;
    //mapa: {ID, vector_id}
    std::unordered_map<std::string, size_t> gameObjecsbyIDs;
    //mapa: {Type, ID}
    std::unordered_map<AssetType, std::string> gameObjectsbyType;

    public:

    Scene(SceneData sceneData);

    void Draw();
    //run on the first frame of the game
    void Start();
    //here runs scripts and functions for every gameobject
    void Update();
};