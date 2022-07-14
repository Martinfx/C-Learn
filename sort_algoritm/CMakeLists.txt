cmake_minimum_required(VERSION 3.0)
set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "-fsanitize=address -fno-omit-frame-pointer -std=gnu11 -O0 -g -Wall -ggdb")

project(sort)
add_executable(${PROJECT_NAME} sort.c)

