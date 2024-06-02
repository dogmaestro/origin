cmake_minimum_required(VERSION 3.20)
project(cppm-homeworks_11_05 VERSION 1.0 LANGUAGES CXX)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(FiguresDynamicLib SHARED Figure.h Figure.cpp
                                     EquilateralTriangle.h EquilateralTriangle.cpp
									 IsoscelesTriangle.h IsoscelesTriangle.cpp
									 Parallelogram.h Parallelogram.cpp
									 Quadrangle.h Quadrangle.cpp
									 Rectangle.h Rectangle.cpp
									 RectangularTriangle.h RectangularTriangle.cpp
									 Rhomb.h Rhomb.cpp
									 Square.h Square.cpp
									 Triangle.h Triangle.cpp)
add_executable(cppm-homeworks_11_05 cppm-homeworks_11_05_client.cpp)
target_link_libraries(cppm-homeworks_11_05 FiguresDynamicLib)
