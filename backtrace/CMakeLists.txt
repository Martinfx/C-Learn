cmake_minimum_required(VERSION 3.0)
project(backtrace)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lunwind -rdynamic -lexecinfo")

if ("${CMAKE_SYSTEM_NAME}" MATCHES "(Free|Net|Open|DragonFly)BSD")
  #set(CMAKE_REQUIRED_INCLUDES "/usr/local/include /usr/include")
  #set(CMAKE_REQUIRED_LIBRARIES "/usr/local/lib")

  find_path(LIBUNWIND_INCLUDE_DIR "libunwind.h" PATHS /usr/local/include)
  find_library(LIBUNWIND_LIBRARIES NAMES "unwind")

  list(APPEND CMAKE_REQUIRED_INCLUDES ${LIBUNWIND_INCLUDE_DIR})
  list(APPEND CMAKE_REQUIRED_LIBRARIES ${LIBUNWIND_LIBRARIES})

  message(STATUS ${LIBUNWIND_INCLUDE_DIR})
  message(STATUS ${LIBUNWIND_LIBRARY})
endif()

add_executable(${PROJECT_NAME} "backtrace.c")
