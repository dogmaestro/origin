#include "EquilateralTriangle.h"
#include "IsoscelesTriangle.h"

EquilateralTriangle::EquilateralTriangle(double _a) :
	IsoscelesTriangle(_a, _a, 60, 60) {
	name = "Равносторонний треугольник";
}