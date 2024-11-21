#pragma once

#include "OmniBrew/Cores/GraphicsCore/Common/Shaders/Shader.hpp"

#include <vector>

#define OB_SHADER_LIMIT 255

namespace OmniBrew::Core::GraphicsCore::ResourceManager{
    // Shaders
    extern Shader* allocatedShaders[OB_SHADER_LIMIT];
    extern int freeShaderPointer;

    void AllocateAsset(Shader* shader);
    void RemoveShader(Shader* shader);

    void CleanAllResources();
}