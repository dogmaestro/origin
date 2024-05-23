#pragma once
#include "Triangle.h"

class RectangularTriangle : public Triangle {
public:
	RectangularTriangle(int _a, int _b, int _c, int _A, int _B);
	std::string getCreationInfo();
};