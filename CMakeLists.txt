cmake_minimum_required(VERSION 3.30)
project(solray)

set(CMAKE_CXX_STANDARD 20)

add_library(solray SHARED library.cpp)
