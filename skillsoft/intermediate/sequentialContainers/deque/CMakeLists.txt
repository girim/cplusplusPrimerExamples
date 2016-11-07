cmake_minimum_required(VERSION 3.5.1)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

project(skillsoft)
add_executable(deque_element_access  ../Plane.cpp deque_element_access.cpp)

