cmake_minimum_required(VERSION 3.13)


# give a name to the project
project(myAssertTest LANGUAGES C CXX)

# files to compile
add_executable(myAssertTest src/main.cpp src/Plop.hpp)

# compilation flags
target_compile_features(myAssertTest PRIVATE cxx_std_11)
target_compile_options(myAssertTest PRIVATE -Wall)

