#include "OmniBrew/Cores/GraphicsCore/WindowsGL/Shaders/ShaderWindows.hpp"

#include "OmniBrew/PlatformIncludes/OpenGL.hpp"

using namespace OmniBrew::Core::GraphicsCore;

void Shader::use(){
    glUseProgram(((ShaderWindows*)this)->ID);
}

ShaderWindows::~ShaderWindows(){
    glDeleteProgram(this->ID);
}