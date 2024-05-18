#include "Quadrangle.h"
#include "Parallelogram.h"

Parallelogram::Parallelogram(double _a, double _b, double _A, double _B) :
	Quadrangle(_a, _b, _a, _b, _A, _B, _A, _B) {
	name = "Параллелограмм";
}