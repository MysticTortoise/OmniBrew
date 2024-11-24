#ifdef ME_PLATFORM_WINDOWS

#include "OmniBrew/Cores/GraphicsCore/Common/Shaders/ShaderFactory.hpp"
#include "OmniBrew/Cores/GraphicsCore/Common/Shaders/Shader.hpp"

#include "OmniBrew/Cores/GraphicsCore/Windows/Shaders/ShaderWindows.hpp"

#include "OmniBrew/Cores/GraphicsCore/Common/ResourceManager.hpp"

#include "OmniBrew/PlatformIncludes/OpenGL.hpp"

using namespace OmniBrew::Core::GraphicsCore;


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
    ResourceManager::shaderList.push_back(shader);

    return shader;
}
#endif