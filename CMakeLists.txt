cmake_minimum_required(VERSION 3.11)
project(game_of_life)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/Game.cpp
        src/Handlers/keyboardHandler.cpp
        include/Handlers/keyboardHandler.h
)

# Create executable
add_executable(game_of_life ${SOURCES})

# Link raylib and required libraries
target_link_libraries(game_of_life
    raylib
    GL
    m
    pthread
    dl
    rt
    X11
)
