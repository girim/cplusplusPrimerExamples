cmake_minimum_required(VERSION 3.5.1)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++0x")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(associativeContainers)
add_executable(map_iterators ../Cone.cpp map_iterators.cpp)
