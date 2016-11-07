cmake_minimum_required(VERSION 3.5.1)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

project(skillsoft)
add_executable(forward_list_remove  ../Plane.cpp forward_list_remove.cpp)

