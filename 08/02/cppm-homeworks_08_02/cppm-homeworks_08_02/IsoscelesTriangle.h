#pragma once
#include "Triangle.h"

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int _a, int _b, int _A, int _B);
	std::string getCreationInfo();
};