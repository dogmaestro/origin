#include "Rectangle.h"
#include "Quadrangle.h"


Rectangle::Rectangle(double _a, double _b) :
	Quadrangle(_a, _b, _a, _b, 90, 90, 90, 90) {
	name = "Прямоугольник";
}