cmake_minimum_required(VERSION 3.15)

project(integral)

# file to comile
add_executable(integral src/main.cpp)

# compilation flags
target_compile_features(integral PRIVATE cxx_std_11)
target_compile_options(integral PRIVATE -Wall -O2) 


