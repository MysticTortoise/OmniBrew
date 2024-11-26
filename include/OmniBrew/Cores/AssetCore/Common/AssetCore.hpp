#pragma once

#include <string>

namespace OmniBrew::Core::AssetCore
{
    int Initialize();
    void DeInitialize();

    const char* GetBytesFromFile(const std::string assetPath, int& fileSize);
    const char* GetBytesFromFile(const std::string assetPath);
    std::string GetTextFromFile(const std::string filePath);
}
