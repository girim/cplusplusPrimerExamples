cmake_minimum_required(VERSION 3.5.1)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++0x")
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

project(skillsoft)
add_executable(vector_bool Plane.cpp vector_bool.cpp)

