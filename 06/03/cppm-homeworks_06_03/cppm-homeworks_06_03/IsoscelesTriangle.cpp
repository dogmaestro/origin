#include "IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(double _a, double _b, double _A, double _B) :
	Triangle(_a, _b, _a, _A, _B, _A) {
	name = "Равнобедренный треугольник";
}
