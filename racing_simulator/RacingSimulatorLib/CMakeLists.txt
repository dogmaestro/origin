cmake_minimum_required(VERSION 3.20)
project(RacingSimulatorLib VERSION 1.0 LANGUAGES CXX)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

#Для студии ставим флаг, что кодировка исходников UTF-8
if(MSVC)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

set (SOURCES 
    LandVehicle.cpp
    AirVehicle.cpp
    Camel.cpp
    CamelSpeedster.cpp 
    Centaur.cpp 
    AllTerrainBoots.cpp 
    MagicCarpet.cpp
    Eagle.cpp 
    Broom.cpp 
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

