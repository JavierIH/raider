
project(testserial)

cmake_minimum_required(VERSION 2.6)

add_library(serialib SHARED serialib.cpp)

add_executable(Example1 Example1.cpp)

target_link_libraries(Example1 serialib)
