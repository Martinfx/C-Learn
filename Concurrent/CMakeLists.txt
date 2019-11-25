cmake_minimum_required(VERSION 2.8)
set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "-O0 -g -Wall -ggdb")

project(MultipleProcesses)
add_executable(${PROJECT_NAME} "multipleprocesses.c")
