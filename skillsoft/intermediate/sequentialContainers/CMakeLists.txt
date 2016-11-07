cmake_minimum_required(VERSION 3.5.1)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

project(sequential)
add_executable(vector_pop_back  Plane.cpp vector_pop_back.cpp)

