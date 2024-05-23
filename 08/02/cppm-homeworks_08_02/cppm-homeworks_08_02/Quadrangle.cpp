#include <iostream>
#include "Quadrangle.h"
#include "FigureError.h"

Quadrangle::Quadrangle(int _a, int _b, int _c, int _d, int _A, int _B, int _C, int _D) : a(_a), b(_b), c(_c), d(_d), A(_A), B(_B), C(_C), D(_D) {
	name = "Четырехугольник";
	sides_count = 4;
	if (sides_count != 4) {
		throw FigureError("Количество сторон не равно 4");
	}
	else if (A + B + C + D != 360) {
		throw FigureError("Сумма углов не равна 360");
	}
}

std::string Quadrangle::getCreationInfo() {
	return name + " (стороны " + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + ", " + std::to_string(d) + "; углы " + std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ", " + std::to_string(D) + ") создан ";
}