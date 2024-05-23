#include "Rectangle.h"
#include "Quadrangle.h"
#include "FigureError.h"

Rectangle::Rectangle(int _a, int _b) :
	Quadrangle(_a, _b, _a, _b, 90, 90, 90, 90) {
	name = "Прямоугольник";
	if (!( a == c && b == d)) {
		throw FigureError("Стороны a,c и b,d попарно не равны");
	}
	else if (!(A == 90 && B == 90 && C == 90 && D == 90)) {
		throw FigureError("Все углы не равны 90");
	}
}

std::string Rectangle::getCreationInfo() {
	return name + " (стороны " + std::to_string(a) + ", " + std::to_string(b) + ") создан ";
}