#include "OmniBrew/InfoMacros.hpp"
#ifdef ME_PLATFORM_WINDOWS

#include "OmniBrew/Cores/SystemCore/Windows/SystemCoreWindows.hpp"
#include "OmniBrew/PlatformIncludes/OpenGL.hpp"

using namespace OmniBrew::Core;
using namespace SystemCore;

GLFWwindow* SystemCore::window = nullptr;

int SystemCore::Initialize(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800,600, "OmniBrew", NULL, NULL);
    if(window == NULL){
        ERROR("Failed to create GLFW window!");
        return -1;
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        ERROR("Failed to initialize GLAD!");
        return -1;
    }
    return 0;
}
void SystemCore::DeInitialize(){
    glfwTerminate();
}

void SystemCore::Update(){
    isRunning = !glfwWindowShouldClose(window);
    glfwPollEvents();
}


#endif