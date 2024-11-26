#include "OmniBrew/Cores/AssetCore/WindowsRawFS/AssetCoreWindows.hpp"

#include "OmniBrew/InfoMacros.hpp"

#include <filesystem>
#include <fstream>

#define ASSET_SUBPATH "/Assets/"


using namespace OmniBrew::Core;
using namespace OmniBrew::Core::AssetCore;

#ifdef OB_WORK_ENV
std::string AssetCore::fileSystemPath = std::filesystem::current_path().generic_string().substr(0,25) + ASSET_SUBPATH;
#else
std::string AssetCore::fileSystemPath = std::filesystem::current_path().generic_string() + ASSET_SUBPATH;
#endif	

int AssetCore::Initialize() {
	if (!std::filesystem::is_directory(fileSystemPath))
	{
		ERROR("Asset path doesn't exist! Path should be: " + fileSystemPath);
		return -1;
	}
	return 1;
}

void AssetCore::DeInitialize() {

}

const char* AssetCore::GetBytesFromFile(const std::string assetPath, int& fileSize) {
	std::string fullFilePath = fileSystemPath + assetPath;
#ifndef OB_NO_SAFETY
	if (!std::filesystem::exists(fullFilePath)) {
		ERROR("File doesn't exist! Looking for file: " + fullFilePath);
		return nullptr;
	}
#endif // OB_NO_SAFETY


	std::ifstream inFile(fullFilePath, std::ios_base::binary);
	inFile.seekg(0, std::ios::end);
	size_t length = inFile.tellg();
	fileSize = length;
	inFile.seekg(0, std::ios::beg);

	char* buffer = new char[fileSize+1];
	inFile.read(buffer, length);
	inFile.close();
	buffer[fileSize] = 0x00;
	return buffer;
}

const char* AssetCore::GetBytesFromFile(const std::string assetPath) {
	int size;
	return AssetCore::GetBytesFromFile(assetPath, size);
}