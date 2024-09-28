cmake_minimum_required(VERSION 3.10)

if(MSVC)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

set(PostgreSQL_ADDITIONAL_VERSIONS "16")

project(sqlcpp06)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

link_directories("/usr/local/lib")

add_executable(sqlcpp06 main.cpp)

target_link_libraries(sqlcpp06 
    "/usr/local/lib/libwt.so"
    "/usr/local/lib/libwtdbo.so"
    "/usr/local/lib/libwtdbopostgres.so"
    pq
)
