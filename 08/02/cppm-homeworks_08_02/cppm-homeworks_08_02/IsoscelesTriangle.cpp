#include <iostream>
#include "Triangle.h"
#include "IsoscelesTriangle.h"
#include "FigureError.h"

IsoscelesTriangle::IsoscelesTriangle(int _a, int _b, int _A, int _B) :
	Triangle(_a, _b, _a, _A, _B, _A) {
	name = "Равнобедренный треугольник";
	if (a != c) {
		throw FigureError("Стороны a и c не равны");
	}
	else if (A != C) {
		throw FigureError("Углы A и C не равны");
	}
}

std::string IsoscelesTriangle::getCreationInfo() {
	return name + " (стороны " + std::to_string(a) + ", " + std::to_string(b) + "; углы " + std::to_string(A) + ", " + std::to_string(B) + ") создан ";
}