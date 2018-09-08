cmake_minimum_required(VERSION 3.5.1)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(skillsoft)
add_executable(bit_access bit_access.cpp)