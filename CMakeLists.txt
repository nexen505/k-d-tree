cmake_minimum_required(VERSION 3.12)
project(cpp_k_d_tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        cpp_k_d_tree
        main.cpp
        store/VectorStore.h
        store/vector/VectorOfVectors.cpp
        store/vector/VectorOfVectors.h
        vectorGenerators/RandomVectorGenerator.cpp
        vectorGenerators/RandomVectorGenerator.h
        vectorGenerators/VectorGenerator.h
        "store/k-d tree/KdTree.cpp"
        "store/k-d tree/KdTree.h"
        vectorGenerators/CommandLineGenerator.cpp
        vectorGenerators/CommandLineGenerator.h
        vectorGenerators/FileGenerator.cpp
        vectorGenerators/FileGenerator.h
)
add_custom_command(
        TARGET cpp_k_d_tree
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/vectors_file.txt"
        "$<TARGET_FILE_DIR:cpp_k_d_tree>/vectors_file.txt"
)