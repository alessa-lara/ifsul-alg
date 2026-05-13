cmake_minimum_required(VERSION 3.10.0)
project(lib VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_BUILD_TYPE Debug)

add_executable(lib main.cpp lib/queue.hpp)

