#pragma once
#include "Quadrangle.h" 

#ifdef CPPM_HOMEWORKS_11_04_EXPORTS
#define CPPM_HOMEWORKS_11_04_API __declspec(dllexport)
#else
#define CPPM_HOMEWORKS_11_04_API __declspec(dllimport)
#endif

class Rectangle : public Quadrangle {
public:
	CPPM_HOMEWORKS_11_04_API Rectangle(double _a, double _b);
};

