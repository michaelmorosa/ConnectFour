cmake_minimum_required(VERSION 3.19)
project(ConnectFour)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConnectFour main.cpp board.cpp board.h game.cpp game.h player.cpp player.h move.cpp move.h)