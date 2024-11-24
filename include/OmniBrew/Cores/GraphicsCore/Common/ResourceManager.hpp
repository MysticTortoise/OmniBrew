#pragma once

#include "OmniBrew/Cores/GraphicsCore/Common/Shaders/Shader.hpp"
#include <vector>


namespace OmniBrew::Core::GraphicsCore::ResourceManager{
    extern std::vector<Shader*> shaderList;


    void CleanAllAssets();
}