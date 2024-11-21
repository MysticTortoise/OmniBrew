#pragma once

#include "MultiEngine/Cores/GraphicsCore/Shaders/Shader.hpp"

namespace MultiEngine::Core::GraphicsCore::ShaderFactory{
    Shader* CreateProgrammableFromCode(const char* vertexShaderSource, const char* fragmentShaderSource);
}