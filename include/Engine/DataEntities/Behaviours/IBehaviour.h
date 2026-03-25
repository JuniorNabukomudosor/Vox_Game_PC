#pragma once
#include <Engine/DataEntities/Behaviours/BehaviourTypes.h>
#include <Engine/DataEntities/GameObjects/GameObject.h>
#include <vector>

class IBehaviour
{
    public:
    GameObject&  parentGameobject;
    std::vector<BehaviourRuntimeParam> params;

    IBehaviour(GameObject& gameObject);

    virtual void Start() = 0;
    virtual void Update(float deltatime) = 0;
    virtual void LateUpdate(float deltatime) = 0;
};
