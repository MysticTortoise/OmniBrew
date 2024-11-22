#include "OmniBrew/OmniBrew.hpp"

#include "OmniBrew/Cores/SystemCore/Common/SystemCore.hpp"
#include "OmniBrew/Cores/GraphicsCore/Common/GraphicsCore.hpp"

using namespace OmniBrew;
using namespace OmniBrew::Core;


void OmniBrew::Main(){
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