#include <Engine/DataEntities/Behaviours/IBehaviour.h>

IBehaviour::IBehaviour(GameObject& gameObject)
: parentGameobject(gameObject),   params(std::vector<BehaviourRuntimeParam>())
{}