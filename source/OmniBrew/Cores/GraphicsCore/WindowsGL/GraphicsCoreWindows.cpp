#ifdef OB_PLATFORM_WINDOWS
#include "OmniBrew/Cores/GraphicsCore/WindowsGL/GraphicsCoreWindows.hpp"
#include "OmniBrew/Cores/SystemCore/WindowsGL/SystemCoreWindows.hpp"

#include "OmniBrew/Cores/GraphicsCore/Common/Shaders/ShaderFactory.hpp"
#include "OmniBrew/Cores/GraphicsCore/Common/ResourceManager.hpp"

#include "OmniBrew/PlatformIncludes/OpenGL.hpp"

using namespace OmniBrew::Core;
using namespace GraphicsCore;

void FramebufferSizeCallback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}


float vertices[] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
};
unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};  


unsigned int VAO;
unsigned int EBO;
Shader* shader;

int GraphicsCore::Initialize(){
    glfwSetFramebufferSizeCallback(SystemCore::window, FramebufferSizeCallback);
    glViewport(0,0,800,600);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    shader = GraphicsCore::ShaderFactory::CreateProgrammableFromFile("Shaders/testShader.vert", "Shaders/testShader.frag");
    shader->use();

    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    return 0;
}

void GraphicsCore::DeInitialize(){
    glDeleteVertexArrays(1, &VAO);
    ResourceManager::CleanAllAssets();
}


void GraphicsCore::Update(){
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shader->use();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    glfwSwapBuffers(SystemCore::window);
}
#endif