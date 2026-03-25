#pragma once
#include <Engine/DataEntities/Behaviours/BehaviourTypes.h>
#include <vector>

class IBehaviour
{
    public:
    std::vector<BehaviourRuntimeParam> params;
    IBehaviour();

    virtual void Start() = 0;
    virtual void Update() = 0;
};
