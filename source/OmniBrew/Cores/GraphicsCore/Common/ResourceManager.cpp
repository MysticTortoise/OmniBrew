#include "OmniBrew/Cores/GraphicsCore/Common/ResourceManager.hpp"

#include <stdexcept>

namespace OmniBrew::Core::GraphicsCore::ResourceManager{
    Shader* allocatedShaders[OB_SHADER_LIMIT];
    int endOfShaderList = 0;

    // TODO: Turn this all into a Class instead of boilerplate shit for every type of asset.
    // OmniBrew::Data::ItemList ?
    void CleanAllShaders(){ // Removes ALL currently allocated shaders
        for(int i=0; i<endOfShaderList; i++){
            if(allocatedShaders[i] != nullptr){
                delete allocatedShaders[i];
                allocatedShaders[i] = nullptr;
            }
        }
        endOfShaderList = 0;
    }
    void AllocateShader(Shader* shader){ // Adds a new shader to the shader list.
        int newShaderIndex = endOfShaderList+1;
        for(int i = 0; i < endOfShaderList; i++){
            Shader* currShader = allocatedShaders[i];
            if(currShader == shader){
                return;
            }
            if(currShader == nullptr){
                newShaderIndex = i;
            }
        }
        allocatedShaders[newShaderIndex] = shader;
    }
    void RemoveShader(Shader* shader){
        for(int i = 0; i < OB_SHADER_LIMIT; i++){
            if(shader == allocatedShaders[i]){
                delete allocatedShaders[i];
                allocatedShaders[i] = nullptr;
                freeShaderPointer = freeShaderPointer>i ? i : freeShaderPointer;
            }
        }
    }


    void CleanAllResources(){
        CleanAllShaders();
    }
}