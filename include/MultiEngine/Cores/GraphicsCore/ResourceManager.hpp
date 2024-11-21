#pragma once

#include "MultiEngine/Cores/GraphicsCore/Shaders/Shader.hpp"

#include <vector>

#define RES_SHADERLIST_INDEX_TYPE byte

namespace MultiEngine::Core::GraphicsCore::ResourceManager{
    extern Shader* shaders[byte.];

    void CleanAllResources(constexpr());
}