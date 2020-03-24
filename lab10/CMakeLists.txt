cmake_minimum_required(VERSION 3.10)
project(queuetest)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(rwg main.cpp Queue.h)
