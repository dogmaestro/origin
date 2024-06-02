#pragma once
#include "Rectangle.h"

#ifdef CPPM_HOMEWORKS_11_04_EXPORTS
#define CPPM_HOMEWORKS_11_04_API __declspec(dllexport)
#else
#define CPPM_HOMEWORKS_11_04_API __declspec(dllimport)
#endif

class Square : public Rectangle {
public:
	CPPM_HOMEWORKS_11_04_API Square(double _a);
};

