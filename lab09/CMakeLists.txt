cmake_minimum_required(VERSION 3.12)
project(lab09)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab09
        CMakeLists.txt
        cmake-build-debug/dictionary.txt
        main.cpp
        rwg.cpp
        rwg.h)
