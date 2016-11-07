cmake_minimum_required(VERSION 3.5.1)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++0x -pthread")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(headerFiles)
add_executable(MainApp
                MyClass.cpp
                A.cpp
                B.cpp
                C.cpp
                MainApp.cpp)
