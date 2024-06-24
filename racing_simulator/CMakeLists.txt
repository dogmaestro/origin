cmake_minimum_required(VERSION 3.20)
project(racing_simulator VERSION 1.0 LANGUAGES CXX)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

#Для студии ставим флаг, что кодировка исходников UTF-8
if(MSVC)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()


set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

add_subdirectory(RacingSimulatorLib)

add_executable(${PROJECT_NAME} racing_simulator_client.cpp)
#include_directories(RacingSimulatorLib)
target_link_libraries(${PROJECT_NAME} PRIVATE RacingSimulatorLib)
