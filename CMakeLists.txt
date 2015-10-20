cmake_minimum_required(VERSION 3.3)
project(RadioTide)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c src/RadioTide_Type.h)
add_executable(RadioTide ${SOURCE_FILES})