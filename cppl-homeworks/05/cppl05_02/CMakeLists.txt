cmake_minimum_required(VERSION 3.18.0)
project(cppl05_02)

if(MSVC)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

add_executable(cppl05_02 cppl05_02.cpp)
