cmake_minimum_required(VERSION 3.0)
set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "-fsanitize=address -fno-omit-frame-pointer -std=gnu11 -O0 -g -Wall -ggdb -lstdthreads -DDEBUG=1")

#option(CLANG_MSAN "Enable Clang memory sanitizer" ON)
#if (CLANG_MSAN)s
#    set (CMAKE_CXX_FLAGS "-fsanitize=address -fno-omit-frame-pointer")
#endif()

option(CLANG_TSAN "Enable Clang threads sanitizer" ON)
if (CLANG_TSAN)
    set (CMAKE_CXX_FLAGS "-fsanitize=thread")
endif()

project(test_queue)
add_executable(${PROJECT_NAME} test_queue.c)

project(test_deque)
add_executable(${PROJECT_NAME} test_deque.c)

project(test_vector)
add_executable(${PROJECT_NAME} test_vector.c)

project(test_list)
add_executable(${PROJECT_NAME} test_list.c)

project(test_thread_list)
add_executable(${PROJECT_NAME} test_thread_list.c)

project(test_thread_queue)
add_executable(${PROJECT_NAME} test_thread_queue.c)

project(test_ddlist)
add_executable(${PROJECT_NAME} test_ddlist.c)

project(test_circlist)
add_executable(${PROJECT_NAME} test_circlist.c)

project(test_ring_buffer)
add_executable(${PROJECT_NAME} test_ring_buffer.c)

project(test_thread_ring_buffer)
add_executable(${PROJECT_NAME} test_thread_ring_buffer.c)

project(test_stack)
add_executable(${PROJECT_NAME} test_stack.c)

project(test_tree)
add_executable(${PROJECT_NAME} test_tree.c)

project(test_experimental)
add_executable(${PROJECT_NAME} experimental.c)
