#include "OmniBrew/Cores/GraphicsCore/Common/ResourceManager.hpp"

namespace OmniBrew::Core::GraphicsCore::ResourceManager{
    std::vector<Shader*> shaderList = std::vector<Shader*>();
    std::vector<Mesh*> meshList = std::vector<Mesh*>();

    template<typename T>
    inline void CleanVectorOfPointers(std::vector<T*>* vec){
        for(int i = 0; i < vec->size(); ++i){
            delete vec->at(i);
        }
        vec->clear();
    }
    void CleanAllAssets(){
        CleanVectorOfPointers<Shader>(&shaderList);
        CleanVectorOfPointers<Mesh>(&meshList);
    }
}