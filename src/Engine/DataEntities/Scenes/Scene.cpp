#include <Engine/DataEntities/Scenes/Scene.h>

Scene::Scene(SceneData data)
: necessaryAssetsStrIds(std::vector<char[64]>()),
gameObjecsbyIDs(std::unordered_map<std::string, size_t>()),
gameObjects(std::vector<GameObject>()), 
gameObjectsbyType(std::unordered_map<AssetType, std::vector<std::string>>()),
sceneData(data)
{}

void Scene::Start()
{
    for(auto& object : gameObjects)
    {
        object.Start();
    }
}

void Scene::Update(float deltatime)
{
    for(auto& object : gameObjects)
    {
        object.Update(deltatime);
    }
}

void Scene::LateUpdate(float deltatime)
{
    for(auto& object : gameObjects)
    {
        object.LateUpdate(deltatime);
    }
}

void Scene::AddGameObject(GameObject object)
{
    this->gameObjects.push_back(object);

    std::string objectId = std::to_string(object.gameObjectData.ID);

    this->gameObjecsbyIDs[objectId]=gameObjects.size()-1;
    
    //primero verificar si
    auto it = gameObjectsbyType.find(object.GetAssetType());
    if(it != gameObjectsbyType.end())
    {
        it->second.push_back(objectId);
    }else
    {
        gameObjectsbyType[object.GetAssetType()] = std::vector<std::string>{objectId};
    }
}
