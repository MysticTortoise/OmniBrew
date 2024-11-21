#pragma once

#include "OmniBrew/Cores/GraphicsCore/Common/Shaders/Shader.hpp"

#include <vector>

#define RES_SHADERLIST_INDEX_TYPE byte

namespace OmniBrew::Core::GraphicsCore::ResourceManager{
    extern Shader* shaders[255];

    void CleanAllResources();
}