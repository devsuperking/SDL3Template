cmake_minimum_required(VERSION 3.31)
project(lww)

set(CMAKE_CXX_STANDARD 20)

if ((APPLE AND NOT CMAKE_SYSTEM_NAME MATCHES "Darwin") OR EMSCRIPTEN)
    set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "")
    set(SDL_SHARED OFF CACHE BOOL "Build SDL shared lib")
else()
    set(SDL_SHARED ON CACHE BOOL "Build SDL shared lib")
endif()

add_subdirectory(thirdparty/sdl)

add_executable(lww src/main.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>")
set(CMAKE_LIBRARY_OUTP  UT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>")

target_link_libraries(lww PRIVATE SDL3::SDL3)