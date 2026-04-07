#include <Engine/DataEntities/Scenes/Scene.h>

Scene::Scene(SceneData data)
: necessaryAssetsStrIds(std::vector<std::string>()),
gameObjecsbyIDs(std::unordered_map<std::string, std::shared_ptr<GameObject>>()),
gameObjects(std::vector<std::shared_ptr<GameObject>>()), 
gameObjectsbyType(std::unordered_map<AssetType, std::vector<std::shared_ptr<GameObject>>>()),
sceneData(data)
{}

void Scene::Start()
{
    for(auto& object : gameObjects)
    {
        object->Start();
    }
}

void Scene::Update(float deltatime)
{
    for(auto& object : gameObjects)
    {
        object->Update(deltatime);
    }
}

void Scene::LateUpdate(float deltatime)
{
    for(auto& object : gameObjects)
    {
        object->LateUpdate(deltatime);
    }
}

void Scene::AddGameObject(GameObject& object)
{
    auto objPointer = std::make_shared<GameObject>(object);
    this->gameObjects.push_back(objPointer);

    std::string objectId = std::to_string(object.gameObjectData.ID);

    this->gameObjecsbyIDs[objectId]=objPointer;
    
    //primero verificar si
    auto it = gameObjectsbyType.find(object.GetAssetType());
    if(it != gameObjectsbyType.end())
    {
        it->second.push_back(objPointer);
    }else
    {
        gameObjectsbyType[object.GetAssetType()] = std::vector<std::shared_ptr<GameObject>>{objPointer};
    }
}

void Scene::Draw()
{
    
}