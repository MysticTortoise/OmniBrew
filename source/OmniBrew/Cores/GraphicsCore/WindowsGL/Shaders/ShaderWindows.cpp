#include "OmniBrew/Cores/GraphicsCore/WindowsGL/Shaders/ShaderWindows.hpp"

#include "OmniBrew/PlatformIncludes/OpenGL.hpp"


using namespace OmniBrew;
using namespace OmniBrew::Core::GraphicsCore;

ShaderWindows::ShaderWindows(int id) :
    ID(id)
{
    GLint count, size;
    GLenum type;

    const GLsizei bufSize = 64;
    GLchar name[bufSize];
    GLsizei length;

    glGetProgramiv(ID, GL_ACTIVE_UNIFORMS, &count);
    for (GLint i = 0; i < count; i++) {
        glGetActiveUniform(ID, (GLuint)i, bufSize, &length, &size, &type, name);
        parameterLocations[std::string(name)] = glGetUniformLocation(ID, name);
    }
}

void Shader::setParameter(const char* parameterName, bool value) {
    ShaderWindows* thisWin = (ShaderWindows*)this;
    this->use();
    glUniform1i(thisWin->parameterLocations.at(parameterName), value);
}
void Shader::setParameter(const char* parameterName, int value) {
    ShaderWindows* thisWin = (ShaderWindows*)this;
    this->use();
    glUniform1i(thisWin->parameterLocations.at(parameterName), value);
}
void Shader::setParameter(const char* parameterName, float value) {
    ShaderWindows* thisWin = (ShaderWindows*)this;
    this->use();
    glUniform1f(thisWin->parameterLocations.at(parameterName), value);
}
void Shader::setParameter(const char* parameterName, Math::Vector2 value) {
    ShaderWindows* thisWin = (ShaderWindows*)this;
    this->use();
    glUniform2f(thisWin->parameterLocations.at(parameterName), value.x, value.y);
}
void Shader::setParameter(const char* parameterName, Math::Vector3 value) {
    ShaderWindows* thisWin = (ShaderWindows*)this;
    this->use();
    glUniform3f(thisWin->parameterLocations.at(parameterName), value.x, value.y, value.z);
}
void Shader::setParameter(const char* parameterName, Math::Vector4 value) {
    ShaderWindows* thisWin = (ShaderWindows*)this;
    this->use();
    glUniform4f(thisWin->parameterLocations.at(parameterName), value.x, value.y, value.z, value.w);
}
void Shader::setParameter(const char* parameterName, Math::Color value) {
    ShaderWindows* thisWin = (ShaderWindows*)this;
    this->use();
    glUniform4f(thisWin->parameterLocations.at(parameterName), value.r, value.g, value.b, value.a);
}


void Shader::use(){
    glUseProgram(((ShaderWindows*)this)->ID);
}

ShaderWindows::~ShaderWindows(){
    glDeleteProgram(this->ID);
}