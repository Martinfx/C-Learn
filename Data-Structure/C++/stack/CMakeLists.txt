cmake_minimum_required(VERSION 3.5)

project(threadsafe_stack LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS  "-fsanitize=address -fno-omit-frame-pointer")

add_executable(threadsafe_stack main.cpp)
