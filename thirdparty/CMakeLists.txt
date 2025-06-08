cmake_minimum_required(VERSION 3.16)

project(MySDLProject)

# Output directories for binaries and libraries per configuration (Debug/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

# Installation prefix inside the build directory (optional)
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}" CACHE INTERNAL "")

# Configure shared/static options depending on platform
if ((APPLE AND NOT CMAKE_SYSTEM_NAME MATCHES "Darwin") OR EMSCRIPTEN)
    set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "")
    set(SDL_SHARED OFF)
else()
    set(SDL_SHARED ON)
endif()

# Enable MSVC parallel compilation if not using Ninja
if(MSVC)
    if(NOT CMAKE_GENERATOR STREQUAL "Ninja")
        add_definitions(/MP)
    endif()
endif()

# Add SDL3 from source
add_subdirectory(sdl)

# Configure SDL_image options
set(SDLIMAGE_VENDORED ON)
set(SDLIMAGE_AVIF OFF)
set(SDLIMAGE_BMP OFF)
set(SDLIMAGE_JPEG OFF)
set(SDLIMAGE_WEBP OFF)

add_subdirectory(sdl_image EXCLUDE_FROM_ALL)

add_library(thirdparty_lib INTERFACE)

target_link_libraries(thirdparty_lib INTERFACE
        SDL3::SDL3
        SDL3_image::SDL3_image
)