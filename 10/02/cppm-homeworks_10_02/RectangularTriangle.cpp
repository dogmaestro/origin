#include "Triangle.h"
#include "RectangularTriangle.h"

RectangularTriangle::RectangularTriangle(double _a, double _b, double _c, double _A, double _B) :
	Triangle(_a, _b, _c, _A, _B, 90) {
	name = "Прямоугольный треугольник";
}