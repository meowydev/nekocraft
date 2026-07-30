cmake_minimum_required(VERSION 4.3) # Put the latest version here

project(nekocraft # Put your project name
        VERSION 0.1.0
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 26) # Put your c++ version supported here
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SFML 3 REQUIRED COMPONENTS
        Graphics
        Window
        Audio
        System)

add_executable(${PROJECT_NAME}
        src/main.cpp
        external/tinyfiledialogs/tinyfiledialogs.c
)

target_include_directories(${PROJECT_NAME} PRIVATE
    external/tinyfiledialogs
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::Audio
        SFML::System
)