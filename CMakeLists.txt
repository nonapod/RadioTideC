cmake_minimum_required(VERSION 3.3)
project(RadioTide)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c99")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(SOURCE_FILES main.c src/RadioTide_Type.h lib/libyutil/Yutil_Node.c lib/libyutil/Yutil_Node.h)
add_executable(RadioTide ${SOURCE_FILES})