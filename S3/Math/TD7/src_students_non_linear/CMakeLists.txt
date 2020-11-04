cmake_minimum_required(VERSION 3.15)

project(zero)

# file to comile
add_executable(zero src/main.cpp)

# compilation flags
target_compile_features(zero PRIVATE cxx_std_11)
target_compile_options(zero PRIVATE -Wall -O2) 


