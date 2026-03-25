#pragma once

enum class AssetType
{
    Sprite,
    Animated_Sprite,
    Audio,
    Uknown
};

constexpr const char* AssetTypeToStr(AssetType a)
{
    switch (a)
    {
        case AssetType::Animated_Sprite: return "ANIMATED_SPRITE";
        case AssetType::Sprite: return "SPRITE";
        case AssetType::Audio: return "AUDIO";
        case AssetType::Uknown: return "?";
        default: return "?";
    }
};

namespace std
{
    template <>
    struct hash<AssetType> 
    {
        size_t operator()(const AssetType& t) const noexcept
        {
            return static_cast<size_t>(t);
        }
    };
}