#pragma once
#include "Quadrangle.h" 

class Rectangle : public Quadrangle {
public:
	Rectangle(int _a, int _b);
	std::string getCreationInfo();
};

