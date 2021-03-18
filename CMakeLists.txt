cmake_minimum_required(VERSION 3.17)
project(ft_containers)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ft_containers
        List.hpp
        Main.cpp
        Node.hpp)
