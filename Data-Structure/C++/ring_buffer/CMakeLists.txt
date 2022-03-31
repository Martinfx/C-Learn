cmake_minimum_required(VERSION 3.5)

project(ring_buffer LANGUAGES CXX)

link_libraries(pthread)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS  "-fsanitize=address -fno-omit-frame-pointer -w -Wall -Wextra")

add_executable(ring_buffer main.cpp)
