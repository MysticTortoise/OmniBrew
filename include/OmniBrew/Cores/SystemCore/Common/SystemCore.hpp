#pragma once

namespace OmniBrew::Core::SystemCore
{
    extern bool isRunning;
    int Initialize();
    void DeInitialize();
    void Update();
}
