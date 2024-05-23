#include <iostream>
#include "Triangle.h"
#include "FigureError.h"

Triangle::Triangle(int _a, int _b, int _c, int _A, int _B, int _C) : a(_a), b(_b), c(_c), A(_A), B(_B), C(_C) {
	name = "Треугольник";
	sides_count = 3;
	if (sides_count != 3) {
		throw FigureError("Количество сторон не равно 3");
	}
	else if (A + B + C != 180) {
		throw FigureError("Сумма углов не равна 180");
	}
}

std::string Triangle::getCreationInfo() {
	return name + " (стороны " + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + "; углы " + std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ") создан ";
}
