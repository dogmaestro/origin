cmake_minimum_required(VERSION 3.10)

if(MSVC)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

set(PostgreSQL_ADDITIONAL_VERSIONS "16")

project(sqlcpp05)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory("/home/libpqxx-7.9.2" libpqxx-build)

add_executable(sqlcpp05 main.cpp)

target_link_libraries(sqlcpp05 pqxx)
