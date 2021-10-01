cmake_minimum_required(VERSION 3.20)
project(ServerProject)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(ServerProject main.cpp Player.cpp Player.h Ball.cpp Ball.h Block.cpp Block.h Game.cpp Game.h)
