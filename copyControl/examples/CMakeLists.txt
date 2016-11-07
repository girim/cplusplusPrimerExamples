cmake_minimum_required(VERSION 3.5.1)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++0x -pthread")
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

project(basics)
add_executable(copyControl copyControl.cpp)
