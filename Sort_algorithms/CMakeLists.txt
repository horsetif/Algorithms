cmake_minimum_required(VERSION 3.10)
project(Sort_algorithms)

set(CMAKE_CXX_STANDARD 11)
include_directories( include )
set(SRC
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        include/base_include.h
        include/SortBase.h
        include/Selection.h
        include/Insertion.h
        include/Shell.h
        include/Merge.h
        include/Quick.h
        include/MaxPQ.h
        include/PQsort.h
        include/IndexMinPQ.h)

link_directories(${PROJECT_SOURCE_DIR})
add_executable(Sort_algorithms ${SRC})