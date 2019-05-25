cmake_minimum_required(VERSION 3.10)
project(String_algorithms)

set(CMAKE_CXX_STANDARD 11)
include_directories( include )
set(SRC ${PROJECT_SOURCE_DIR}/include/LSD.h
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${PROJECT_SOURCE_DIR}/include/MSD.h
        ${PROJECT_SOURCE_DIR}/include/base_include.h
        ${PROJECT_SOURCE_DIR}/include/Quick3string.h
        ${PROJECT_SOURCE_DIR}/include/StringST.h)

link_directories(${PROJECT_SOURCE_DIR})
add_executable(String_algorithms ${SRC})