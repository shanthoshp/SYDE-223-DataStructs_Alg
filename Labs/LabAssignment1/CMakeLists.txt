# cmake_minimum_required(VERSION <specify CMake version here>)
project(LabAssignment1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LabAssignment1
        lab1_polynomial.cpp
        lab1_polynomial.h
        polynomial.txt)
