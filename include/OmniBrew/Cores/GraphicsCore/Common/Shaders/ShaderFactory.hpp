#pragma once

#include "OmniBrew/Cores/GraphicsCore/Common/Shaders/Shader.hpp"

#include <string>

namespace OmniBrew::Core::GraphicsCore::ShaderFactory{
    Shader* CreateProgrammableFromCode(const char* vertexShaderSource, const char* fragmentShaderSource);
    Shader* CreateProgrammableFromFile(const std::string vertexShaderPath, const std::string fragmentShaderPath);
}