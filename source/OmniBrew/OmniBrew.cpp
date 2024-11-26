#include "OmniBrew/OmniBrew.hpp"

#include "OmniBrew/Cores/SystemCore/Common/SystemCore.hpp"
#include "OmniBrew/Cores/GraphicsCore/Common/GraphicsCore.hpp"
#include "OmniBrew/Cores/AssetCore/Common/AssetCore.hpp"

using namespace OmniBrew;
using namespace OmniBrew::Core;

CoreType OmniBrew::Initialize() {
    if (SystemCore::Initialize() < 0)
        return SystemCoreType;
    if (GraphicsCore::Initialize() < 0)
        return GraphicsCoreType;
    if (AssetCore::Initialize() < 0)
        return AssetCoreType;

    return NoCoreType;
}

void OmniBrew::Tick() {
    SystemCore::Update();
    GraphicsCore::Update();
}

void OmniBrew::DeInitialize(CoreType failedCore) {
    switch (failedCore) {
    case AssetCoreType:
        GraphicsCore::DeInitialize();
        [[fallthrough]];

    case GraphicsCoreType:
        SystemCore::DeInitialize();
        [[fallthrough]];

    case SystemCoreType:
    default:
        break;
    }
}


void OmniBrew::Main(){
    CoreType failedCore = Initialize();

    if (failedCore == NoCoreType) {
        while (SystemCore::isRunning) {
            Tick();
        }
    }
    DeInitialize(failedCore);
}