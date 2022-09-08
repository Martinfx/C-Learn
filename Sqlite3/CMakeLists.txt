cmake_minimum_required(VERSION 3.5)

project(SqlAndC LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "CMake version: ${CMAKE_VERSION}")
message(STATUS "CMake generator: ${CMAKE_GENERATOR}")

# Add path for custom modules
#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_path(SQLITE3_INCLUDE_DIR "sqlite3.h" PATHS /usr/local/include)
find_library(SQLITE3_LIBRARIES NAMES "sqlite3")

list(APPEND CMAKE_REQUIRED_INCLUDES ${SQLITE3_INCLUDE_DIR})
list(APPEND CMAKE_REQUIRED_LIBRARIES ${SQLITE3_LIBRARIES})

message(STATUS ${SQLITE3_INCLUDE_DIR})
message(STATUS ${SQLITE3_LIBRARIES})

find_package (sqlite3)
include_directories(${SQLITE3_INCLUDE_DIRS})
add_executable(SqlAndC main.cpp)
target_link_libraries (SqlAndC ${SQLITE3_LIBRARIES})



