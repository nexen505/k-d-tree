cmake_minimum_required(VERSION 3.12)
project(cpp_k_d_tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_k_d_tree main.cpp store/VectorStore.h store/vector/VectorOfVectors.cpp store/vector/VectorOfVectors.h vectorGenerators/RandomVectorGenerator.cpp vectorGenerators/RandomVectorGenerator.h vectorGenerators/VectorGenerator.h "store/k-d tree/KdTree.cpp" "store/k-d tree/KdTree.h")