cmake_minimum_required(VERSION 3.20)
project(ini_parser VERSION 1.0 LANGUAGES CXX)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

if(MSVC)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()


set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

add_subdirectory(Lib)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Lib)

#add_custom_command(TARGET ini_parser PRE_BUILD
#                   COMMAND ${CMAKE_COMMAND} -E copy_directory
#                   ${CMAKE_SOURCE_DIR}/res/ $<TARGET_FILE_DIR:ini_parser>)


set(SOURCE_INI_FILE "${CMAKE_SOURCE_DIR}/res/example.ini")
set(DEST_INI_FILE "${CMAKE_BINARY_DIR}/example.ini")
add_custom_command(
    OUTPUT ${DEST_INI_FILE}
    COMMAND ${CMAKE_COMMAND} -E copy ${SOURCE_INI_FILE} ${DEST_INI_FILE}
    DEPENDS ${SOURCE_INI_FILE} 
    COMMENT "Copying ini file to build directory..."
)
add_custom_target(copy_custom_file ALL DEPENDS ${DEST_INI_FILE})
