#pragma once

#include "OmniBrew/Cores/GraphicsCore/Shaders/Shader.hpp"

#include <vector>

#define RES_SHADERLIST_INDEX_TYPE byte

namespace OmniBrew::Core::GraphicsCore::ResourceManager{
    extern Shader* shaders[byte.];

    void CleanAllResources(constexpr());
}