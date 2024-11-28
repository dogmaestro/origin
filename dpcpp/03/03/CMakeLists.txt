cmake_minimum_required(VERSION 3.10)

if(MSVC)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

project(dpcpp03_03)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(dpcpp03_03 main.cpp)