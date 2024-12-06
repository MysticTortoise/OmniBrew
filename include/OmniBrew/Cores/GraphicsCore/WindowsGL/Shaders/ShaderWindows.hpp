#pragma once

#include "OmniBrew/Cores/GraphicsCore/Common/Shaders/Shader.hpp"

#include <string>
#include <unordered_map>

namespace OmniBrew::Core::GraphicsCore{
    class ShaderWindows : public Shader{
        public:

        unsigned int ID;
        std::unordered_map<std::string, int> parameterLocations;

        ShaderWindows(int id);
        ~ShaderWindows();

    };
}