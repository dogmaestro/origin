#pragma once
#include "IsoscelesTriangle.h"

class EquilateralTriangle : public IsoscelesTriangle {
public:
	EquilateralTriangle(int _a);
	std::string getCreationInfo();
};