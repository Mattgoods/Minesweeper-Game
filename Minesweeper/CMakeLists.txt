cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Minesweeper)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "/opt/SFML")

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
add_executable(Minesweeper main.cpp Random.cpp Random.h TextureManager.cpp TextureManager.h Board.cpp Board.h Tile.cpp Tile.h)
target_link_libraries(Minesweeper sfml-system sfml-window sfml-graphics)