#ifdef OB_PLATFORM_WINDOWS

#include "OmniBrew/Cores/AssetCore/Common/AssetCore.hpp"

#include "OmniBrew/Cores/GraphicsCore/Common/Shaders/ShaderFactory.hpp"
#include "OmniBrew/Cores/GraphicsCore/Common/Shaders/Shader.hpp"
#include "OmniBrew/Cores/GraphicsCore/WindowsGL/Shaders/ShaderWindows.hpp"
#include "OmniBrew/Cores/GraphicsCore/Common/ResourceManager.hpp"

#include "OmniBrew/InfoMacros.hpp"
#include "OmniBrew/PlatformIncludes/OpenGL.hpp"

using namespace OmniBrew::Core::GraphicsCore;


Shader* ShaderFactory::CreateProgrammableFromCode(const char* vertexShaderSource, const char* fragmentShaderSource){
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
#ifndef OB_NO_SAFETY
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        ERROR("Vertex shader failed to compile! Log: " << infoLog);
    }
#endif // !OB_NO_SAFETY

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
#ifndef OB_NO_SAFETY
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        ERROR("Fragment shader failed to compile! Log: " << infoLog);
    }
#endif // !OB_NO_SAFETY



    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    ShaderWindows* shader = new ShaderWindows(shaderProgram);

    ResourceManager::shaderList.push_back(shader);

    return shader;
}

Shader* ShaderFactory::CreateProgrammableFromFile(const std::string vertexShaderPath, const std::string fragmentShaderPath) {
    const char* vertexShaderCode = AssetCore::GetBytesFromFile(vertexShaderPath);
    const char* fragmentShaderCode = AssetCore::GetBytesFromFile(fragmentShaderPath);
    return CreateProgrammableFromCode(vertexShaderCode, fragmentShaderCode);
}
#endif