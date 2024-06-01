#include "Parallelogram.h"
#include "Rhomb.h"

Rhomb::Rhomb(double _a, double _A, double _B) :
	Parallelogram(_a, _a, _A, _B) {
	name = "Ромб";
}