cmake_minimum_required(VERSION 3.13)


# give a name to the project
project(my_vector_test LANGUAGES C CXX)

# files to compile
add_executable(my_vector_test src/main.cpp src/VectorD.cpp src/VectorD.hpp)

# compilation flags
target_compile_features(my_vector_test PRIVATE cxx_std_11)
target_compile_options(my_vector_test PRIVATE -Wall)

