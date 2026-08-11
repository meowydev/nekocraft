cmake_minimum_required(VERSION 4.3) # Put the latest version here

project(nekocraft # Put your project name
        VERSION 0.1.0
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 26) # Put your c++ version supported here
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(raylib CONFIG REQUIRED)

add_executable(${PROJECT_NAME}
        src/main.cpp
        external/tinyfiledialogs/tinyfiledialogs.c
        src/crashhandler/crashhandler.cpp
        src/crashhandler/crashhandler.hpp
        src/structs/Button.cpp
        src/structs/Button.hpp
        src/structs/Block.hpp
        src/structs/BlockID.hpp
        src/chunks/chunkType.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    external/tinyfiledialogs
)

target_link_libraries(${PROJECT_NAME}  # Replace with your project name
        PRIVATE
        raylib
)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(${PROJECT_NAME} PRIVATE  # Replace with your project name
            -Wall
            -Wextra
            -Wpedantic
    )
endif()
