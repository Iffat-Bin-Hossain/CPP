cmake_minimum_required(VERSION 3.24)
project(C__ CUDA)

set(CMAKE_CUDA_STANDARD 23)

add_library(C__ library.cu cse.cpp Constructor.cpp "Linked List2.cpp" LinkedListPractice.cpp LinkedListPractice.cpp LinkedListBasedStack.cpp BST.cpp BST.cpp BST.cpp BST.cpp BST.cpp BST.cpp BST.cpp BST.cpp BSToperations.cpp)

set_target_properties(C__ PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
