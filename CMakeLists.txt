# Project Setup
cmake_minimum_required(VERSION 3.10)
project(OmniBrew)

# Fetch GLFW and GLAD

include(FetchContent)
FetchContent_Declare(glfw GIT_REPOSITORY https://github.com/glfw/glfw.git GIT_TAG master)
FetchContent_Declare(glad GIT_REPOSITORY https://github.com/SasLuca/MyGlad.git GIT_TAG master)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

FetchContent_MakeAvailable(glad)

set(includeDirectories ./include)

file(GLOB_RECURSE sources source/*.cpp)
file(GLOB_RECURSE includes ${includeDirectories} *.hpp *.h)

add_compile_definitions(OB_PLATFORM_WINDOWS OB_DEBUG OB_WORK_ENV)

add_executable(OmniBrew ${sources} ${includes} ${libsources})

target_include_directories(OmniBrew PRIVATE ${includeDirectories})
target_link_libraries(OmniBrew glad glfw)
target_compile_features(OmniBrew PRIVATE cxx_std_17)