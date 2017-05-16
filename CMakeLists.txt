cmake_minimum_required(VERSION 3.7)
project(blu)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCE_FILES ./src/*.cpp)
include_directories(include)

add_executable(blu ${SOURCE_FILES})