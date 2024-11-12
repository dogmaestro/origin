cmake_minimum_required(VERSION 3.10)

if(MSVC)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

project(threadSafeQueue)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(thread_pool STATIC thread_pool.cpp thread_pool.h)
target_include_directories(thread_pool PUBLIC .)

add_executable(threadSafeQueue main.cpp safe_queue.h)

target_link_libraries(threadSafeQueue thread_pool)
