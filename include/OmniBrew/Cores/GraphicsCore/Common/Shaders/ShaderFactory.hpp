#pragma once

#include "OmniBrew/Cores/GraphicsCore/Common/Shaders/Shader.hpp"

namespace OmniBrew::Core::GraphicsCore::ShaderFactory{
    Shader* CreateProgrammableFromCode(const char* vertexShaderSource, const char* fragmentShaderSource);
}