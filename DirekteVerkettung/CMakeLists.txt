cmake_minimum_required(VERSION 3.5)
project(DirekteVerkettung)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Hashing.cpp Hashing.h)
add_executable(DirekteVerkettung ${SOURCE_FILES})