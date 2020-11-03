cmake_minimum_required(VERSION 3.13)


# give a name to the project
project(my_stl_exception_test LANGUAGES C CXX)

# files to compile
add_executable(my_stl_exception_test src/main.cpp)

# compilation flags
target_compile_features(my_stl_exception_test PRIVATE cxx_std_11)
target_compile_options(my_stl_exception_test PRIVATE -Wall)

