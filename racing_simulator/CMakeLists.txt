cmake_minimum_required(VERSION 3.20)
project(racing_simulator VERSION 1.0 LANGUAGES CXX)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

#Для студии ставим флаг, что кодировка исходников UTF-8
if(MSVC)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

add_library(RacingSimulatorLib SHARED Vehicle.h 
                                      LandVehicle.h LandVehicle.cpp
                                      AirVehicle.h AirVehicle.cpp
                                      Camel.h Camel.cpp
                                      CamelSpeedster.h CamelSpeedster.cpp 
                                      Centaur.h Centaur.cpp 
                                      AllTerrainBoots.h AllTerrainBoots.cpp 
                                      MagicCarpet.h MagicCarpet.cpp
                                      Eagle.h Eagle.cpp 
                                      Broom.h Broom.cpp 
                                      VehicleFactory.h )

add_executable(racing_simulator racing_simulator_client.cpp)
target_link_libraries(racing_simulator RacingSimulatorLib)
