#pragma once
#include "Parallelogram.h"

class Rhomb : public Parallelogram {
public:
	Rhomb(int _a, int _A, int _B);
	std::string getCreationInfo();
};