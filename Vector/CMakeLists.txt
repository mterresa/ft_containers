cmake_minimum_required(VERSION 3.17)
project(Vector)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Vector
        Main.cpp
        Vector.hpp)
