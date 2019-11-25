cmake_minimum_required(VERSION 2.8)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "-O0 -g -rdynamic -lexecinfo")

if (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
  list(APPEND system_libs execinfo)
endif()

project(backtrace)
add_executable(${PROJECT_NAME} "backtrace.c")
