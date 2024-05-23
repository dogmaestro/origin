#include "Rectangle.h"
#include "Square.h"
#include "FigureError.h"

Square::Square(int _a) :
	Rectangle(_a, _a) {
	name = "Квадрат";
	if (!(a == c && b == d && a == b)) {
		throw FigureError("Все стороны не равны");
	}
	else if (!(A == 90 && B == 90 && C == 90 && D == 90)) {
		throw FigureError("Все углы не равны 90");
	}
}

std::string Square::getCreationInfo() {
	return name + " (сторона " + std::to_string(a) + ") создан ";
}