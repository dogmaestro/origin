#include <iostream>
#include "Figure.h"
#include "Triangle.h"
#include "RectangularTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhomb.h"
#include "FigureError.h"

int main() {
	try {
		Triangle triangle = Triangle{ 10, 20, 30, 40, 80, 60 };
		std::cout << triangle.getCreationInfo() << std::endl;
	}
	catch (const FigureError& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		RectangularTriangle rectangularTriangle = RectangularTriangle{ 10, 20, 30, 50, 60 };
		std::cout << rectangularTriangle.getCreationInfo() << std::endl;
	}
	catch (const FigureError& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		IsoscelesTriangle isoscelesTriangle = IsoscelesTriangle{ 10, 20, 50, 60 };
		std::cout << isoscelesTriangle.getCreationInfo() << std::endl;
	}
	catch (const FigureError& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		EquilateralTriangle equilateralTriangle = EquilateralTriangle{ 30 };
		std::cout << equilateralTriangle.getCreationInfo() << std::endl;
	}
	catch (const FigureError& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Quadrangle quadrangle = Quadrangle{ 10, 20, 30, 40, 50, 60, 70, 80 };
		std::cout << quadrangle.getCreationInfo() << std::endl;
	}
	catch (const FigureError& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Rectangle rectangle = Rectangle{ 10, 20 };
		std::cout << rectangle.getCreationInfo() << std::endl;
	}
	catch (const FigureError& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Square square = Square{ 20 };
		std::cout << square.getCreationInfo() << std::endl;
	}
	catch (const FigureError& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Parallelogram parallelogram = Parallelogram{ 20, 30, 30, 40 };
		std::cout << parallelogram.getCreationInfo() << std::endl;
	}
	catch (const FigureError& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Rhomb rhomb = Rhomb{ 30, 30, 40 };
		std::cout << rhomb.getCreationInfo() << std::endl;
	}
	catch (const FigureError& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
