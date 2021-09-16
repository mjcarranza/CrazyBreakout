cmake_minimum_required(VERSION 3.19)
project(BreakoutServer)

set(CMAKE_CXX_STANDARD 14)
set(Headers Server.h)

SET(CMAKE_CXX_FLAGS -pthread)

add_executable(BreakoutServer main.cpp Server.cpp)