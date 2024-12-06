#pragma once

#include "OmniBrew/Cores/GraphicsCore/Common/Shaders/Shader.hpp"
#include "OmniBrew/Cores/GraphicsCore/Common/Meshes/Mesh.hpp"

#include <vector>


namespace OmniBrew::Core::GraphicsCore::ResourceManager{
    extern std::vector<Shader*> shaderList;
    extern std::vector<Mesh*> meshList;


    void CleanAllAssets();
}