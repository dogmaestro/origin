#pragma once
#include <string>

class Figure {
public:
	Figure();
	virtual void print_info() = 0;
protected:
	std::string name;
	std::string get_name();
};