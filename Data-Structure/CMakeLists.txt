cmake_minimum_required(VERSION 3.0)
set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "-O0 -g -Wall -ggdb -DDEBUG=1 -fsanitize=address -fno-omit-frame-pointer")

project(test_list)
add_executable(${PROJECT_NAME} test_list.c)

project(test_ddlist)
add_executable(${PROJECT_NAME} test_ddlist.c)

