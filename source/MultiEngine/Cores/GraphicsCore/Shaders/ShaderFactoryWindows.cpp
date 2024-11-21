#ifdef ME_PLATFORM_WINDOWS

#include "MultiEngine/Cores/GraphicsCore/Shaders/ShaderFactory.hpp"
#include "MultiEngine/Cores/GraphicsCore/Shaders/Shader.hpp"

#include "MultiEngine/Cores/GraphicsCore/Shaders/ShaderWindows.hpp"

#include "MultiEngine/PlatformIncludes/OpenGL.hpp"

using namespace MultiEngine::Core::GraphicsCore;


Shader* ShaderFactory::CreateProgrammableFromCode(const char* vertexShaderSource, const char* fragmentShaderSource){
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    ShaderWindows* shader = new ShaderWindows();

    shader->ID = shaderProgram;
    return shader;
}
#endif