#pragma once
#include "Rectangle.h"

class Square : public Rectangle {
public:
	Square(int _a);
	std::string getCreationInfo();
};

