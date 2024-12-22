cmake_minimum_required(VERSION 3.30)
project(sdlTest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH "X:/Code/C++/SDL2/x86_64-w64-mingw32")
set(SDL_IMAGE_PATH "X:/Code/C++/SDL2_image/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL_image REQUIRED)
include_directories(${SDL_IMAGE_INCLUDE_DIR})

add_executable(sdlTest main.cpp
        Game.h
        resources/Game.cpp)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${SDL_IMAGE_LIBRARY})
