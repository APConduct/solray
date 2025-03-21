cmake_minimum_required(VERSION 3.30)
project(solray)

set(RAYLIB_VERSION 5.5)


list(
        APPEND CMAKE_MODULE_PATH
        ${CMAKE_SOURCE_DIR}/cmake
)

include(cmake/fetch_sol.cmake)
include(cmake/fetch_raylib.cmake)

set(CMAKE_CXX_STANDARD 20)

add_library(solray SHARED src/library.cpp
        src/solray.cpp)

target_link_libraries(solray PRIVATE sol2 raylib)

add_subdirectory(examples)
