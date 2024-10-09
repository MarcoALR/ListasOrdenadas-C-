cmake_minimum_required(VERSION 3.25)
project(ListaSingularmenteEncadeada)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ListaSingularmenteEncadeada
        Lista.cpp
        Lista.h
        main.cpp)
