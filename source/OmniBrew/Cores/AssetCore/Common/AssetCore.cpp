#include "OmniBrew/Cores/AssetCore/Common/AssetCore.hpp"

#include "OmniBrew/InfoMacros.hpp"

using namespace OmniBrew::Core;
using namespace OmniBrew::Core::AssetCore;

std::string AssetCore::GetTextFromFile(const std::string filePath) {
	const char* cString = AssetCore::GetBytesFromFile(filePath);
	return std::string(cString);
}