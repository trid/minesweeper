cmake_minimum_required(VERSION 3.22)
project(minesweeper)

set(CMAKE_CXX_STANDARD 20)

add_executable(minesweeper main.cpp minefield.cpp game_state.cpp game_state.h game_state_builder.cpp game_state_builder.h tile_opener.cpp tile_opener.h)
