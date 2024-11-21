cmake_minimum_required(VERSION 3.5)
project(OmniBrew)

set(includeDirectories 
./include
./libraries/include
./includeConfigs)

file(GLOB_RECURSE sources source/*.cpp)
file(GLOB_RECURSE includes ${includeDirectories} *.hpp *.h *.hdef)

file(GLOB_RECURSE libsources libraries/sources/*.c*)

add_compile_definitions(ME_PLATFORM_WINDOWS)

add_executable(OmniBrew ${sources} ${includes} ${libsources})

target_include_directories(OmniBrew PRIVATE ${includeDirectories})

target_link_libraries(OmniBrew ${CMAKE_SOURCE_DIR}/libraries/libs/GLFW/libglfw3.a)