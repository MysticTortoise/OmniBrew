#pragma once

#include "OmniBrew/Cores/GraphicsCore/Shaders/Shader.hpp"

namespace OmniBrew::Core::GraphicsCore::ShaderFactory{
    Shader* CreateProgrammableFromCode(const char* vertexShaderSource, const char* fragmentShaderSource);
}