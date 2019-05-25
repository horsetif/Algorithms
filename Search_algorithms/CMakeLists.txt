cmake_minimum_required(VERSION 3.10)
project(Search_algorithms)

set(CMAKE_CXX_STANDARD 11)

include_directories( include )

set(SRC
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        include/base_exception.h
        include/base_include.h
        include/all_method.h
        include/BinarySearchST.h
        include/SequentialSearchST.h
        include/BST.h
        include/RedBlackBST.h
        include/SeparateChainingHashST.h
        include/LinearProbingHashST.h)

link_directories(${PROJECT_SOURCE_DIR})
add_executable(Search_algorithms ${SRC})
