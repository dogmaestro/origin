#pragma once
#include "Triangle.h"

#ifdef CPPM_HOMEWORKS_11_04_EXPORTS
#define CPPM_HOMEWORKS_11_04_API __declspec(dllexport)
#else
#define CPPM_HOMEWORKS_11_04_API __declspec(dllimport)
#endif

class IsoscelesTriangle : public Triangle {
public:
	CPPM_HOMEWORKS_11_04_API IsoscelesTriangle(double _a, double _b, double _A, double _B);
};