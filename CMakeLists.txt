cmake_minimum_required(VERSION 3.17)

project(AlgorithmsLib VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Release)

file(GLOB SOURCE_DIR "src/lib/*.cc" "src/main.cpp")

add_executable(AlgorithmsLib ${SOURCE_DIR})
target_include_directories(AlgorithmsLib PUBLIC 
                                "${CMAKE_BINARY_DIR}"
                                "${CMAKE_SOURCE_DIR}/include")