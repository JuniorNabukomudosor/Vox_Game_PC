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
}