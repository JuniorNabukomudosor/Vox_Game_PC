#pragma once
#include <Engine/DataEntities/Scenes/Scene.h>
#include <future>

class SceneManager
{
    private:

    std::unordered_map<std::string, Scene> disponibleScenes;
    std::string activeScene;

    public:

    SceneManager();

    void LoadSceneResources(std::string sceneName);
    bool LoadSceneFromFile(const char* path);
    bool SaveScenetoFile(const char* path);

};