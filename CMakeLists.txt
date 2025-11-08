cmake_minimum_required(VERSION 3.28)
project(EdenBoost)

set(CMAKE_CXX_STANDARD 23)
include_directories(include)

add_library(EdenBoost SHARED
        src/tree/TreeNode.h
        src/tree/Tree.cpp
        src/tree/Tree.h
)
