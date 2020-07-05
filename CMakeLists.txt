cmake_minimum_required(VERSION 3.17)

project(AlgorithmsLib VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Release)

include_directories(include/*)
file(GLOB SOURCE_DIR "src/*.cc" "include/*.h")

add_executable(algorithms-lib ${SOURCE_DIR})
