#include <iostream>
#include "EquilateralTriangle.h"
#include "IsoscelesTriangle.h"
#include "FigureError.h"

EquilateralTriangle::EquilateralTriangle(int _a) :
	IsoscelesTriangle(_a, _a, 60, 60) {
	name = "Равносторонний треугольник";
	if (!(a == b && b == c)) {
		throw FigureError("Все стороны не равны");
	}
	else if (!(A == 60 && B == 60 && C == 60)) {
		throw FigureError("Все углы не равны 60");
	}
}

std::string EquilateralTriangle::getCreationInfo() {
	return name + " (сторона " + std::to_string(a) +  ") создан ";
}