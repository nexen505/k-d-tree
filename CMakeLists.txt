cmake_minimum_required(VERSION 3.12)
project(cpp_k_d_tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_k_d_tree main.cpp VectorStore.h VectorOfVectors.cpp VectorOfVectors.h vectorGenerators/RandomVectorGenerator.cpp vectorGenerators/RandomVectorGenerator.h vectorGenerators/VectorGenerator.h)