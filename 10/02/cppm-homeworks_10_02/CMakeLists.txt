cmake_minimum_required(VERSION 3.20)
project(cppm-homeworks_10_02 VERSION 1.0 LANGUAGES CXX)
set(source_files cppm-homeworks_10_02.cpp 
                 EquilateralTriangle.cpp
				 Figure.cpp
				 IsoscelesTriangle.cpp
				 Parallelogram.cpp
				 Quadrangle.cpp
				 Rectangle.cpp
				 RectangularTriangle.cpp
				 Rhomb.cpp
				 Square.cpp
				 Triangle.cpp)
add_executable(cppm-homeworks_10_02 ${source_files})