cmake_minimum_required(VERSION 3.13)


# give a name to the project
project(TP9 LANGUAGES C CXX)

# files to compile
add_executable(TP9 src/main.cpp)

# compilation flags
target_compile_features(TP9 PRIVATE cxx_std_11)
target_compile_options(TP9 PRIVATE -Wall)
