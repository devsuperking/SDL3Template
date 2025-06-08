cmake_minimum_required(VERSION 3.16)
project(MySDLProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(thirdparty)

add_executable(MySDLApp src/main.cpp)

target_link_libraries(MySDLApp PRIVATE thirdparty_lib)

if (WIN32)
    target_compile_definitions(MySDLApp PRIVATE SDL_MAIN_HANDLED)
endif()
