#pragma once

#include "OmniBrew/Cores/CoreEnums.hpp"

namespace OmniBrew
{
    CoreType Initialize();
    void Tick();
    void DeInitialize(CoreType failedCore);
    void Main();
}