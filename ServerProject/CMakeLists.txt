cmake_minimum_required(VERSION 3.20)
project(ServerProject)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(ServerProject main.cpp)
