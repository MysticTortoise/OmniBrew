#include "MultiEngine/MultiEngine.hpp"

#include "MultiEngine/Cores/SystemCore/SystemCore.hpp"
#include "MultiEngine/Cores/GraphicsCore/GraphicsCore.hpp"

using namespace MultiEngine;
using namespace MultiEngine::Core;


void MultiEngine::Main(){
    if(SystemCore::Initialize() < 0)
    {
        goto systemCoreLabel;
    }
    if(GraphicsCore::Initialize() < 0){
        goto graphicsCoreLabel;
    }

    while(SystemCore::isRunning){
        SystemCore::Update();
        GraphicsCore::Update();
    }
graphicsCoreLabel:
    GraphicsCore::DeInitialize();
systemCoreLabel:
    SystemCore::DeInitialize();
}