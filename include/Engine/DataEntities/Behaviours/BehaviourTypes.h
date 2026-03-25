#pragma once
#include <cstdint>
#include <string>
#include <any>
#include <vector>

enum class BehaviourParamType
{
    BOOL,
    INT,
    FLOAT,
    SHORT,
    LONG,
    ULONG_LONG,
    UINT,
    CHAR,
    STRING,
    ANY_VECTOR
};

union BehaviourParamDynamicValue
{
    BehaviourParamType type;
    uint32_t count;
    uint32_t objectSize;
};

union BehaviourParamSimpleValue
{
    float fValue;
    int iValue;
    bool bValue;
    short sValue;
    long lValue;
    uint32_t uintValue;
    //este mismo sirve para object id
    unsigned long long ulonglongValue;
    char cValue;
};

struct BehaviourParam
{
    char name[64];
    BehaviourParamType type;
    BehaviourParamSimpleValue value;
    BehaviourParamDynamicValue d_value;
};

struct BehaviourRuntimeParam
{
    std::string name;
    BehaviourParamType type;
    //valor multitipo
    std::any runtimeValue;
};