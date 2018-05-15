cmake_minimum_required(VERSION 3.5.1)
project(skillsoft)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(foldExpressions foldExpressions.cpp)    