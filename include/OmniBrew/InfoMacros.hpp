#pragma once
#ifdef OB_DEBUG

#ifdef OB_PLATFORM_WINDOWS
#include <iostream>

#define PRINT(MSG) std::cout << MSG << std::endl
#define ERROR(MSG) PRINT("ERROR: " << MSG << std::endl)

#endif // OB_PLATFORM_WINDOWS

#endif // OB_DEBUG