cmake_minimum_required(VERSION 3.0)
set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "-w -O0 -g -Wall -ggdb -lstdthreads  -DDEBUG=1 -fsanitize=address -fno-omit-frame-pointer")

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

project(test_stack)
add_executable(${PROJECT_NAME} test_stack.c)

project(test_tree)
add_executable(${PROJECT_NAME} test_tree.c)
