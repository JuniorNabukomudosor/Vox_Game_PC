#pragma once
#include <Engine/DataEntities/GameObjects/GameObject.h>
#include <vector>
#include <unordered_map>
#include <string>
#include <Engine/Assets/AssetTypeEnum.h>
#include <Engine/DataEntities/Scenes/SceneData.h>

class SceneManager;

class Scene
{
    private:

    SceneData sceneData;

    std::vector<char[64]> necessaryAssetsStrIds;
    
    std::vector<GameObject> gameObjects;
    //mapa: {ID, vector_id}
    std::unordered_map<std::string, size_t> gameObjecsbyIDs;
    //mapa: {Type, vector<ID>}
    std::unordered_map<AssetType, std::vector<std::string>> gameObjectsbyType;

    public:

    Scene(SceneData sceneData);

    void Draw();
    //run on the first frame of the game
    void Start();
    //here runs scripts and functions for every gameobject
    void Update(float deltatime);
    //run after every update
    void LateUpdate(float deltatime);

    void AddGameObject(GameObject object);
    std::vector<GameObject>& GetGameObjectsByType(AssetType& type);
    GameObject&  GetGameObjectByID(std::string& id);
    void DeleteGameObjectByID(std::string& id);
    void SetSavePath(const char* path);

    void Exit();

    friend class SceneManager;
};