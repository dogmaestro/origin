#pragma once
#include "IsoscelesTriangle.h"


#ifdef CPPM_HOMEWORKS_11_04_EXPORTS
#define CPPM_HOMEWORKS_11_04_API __declspec(dllexport)
#else
#define CPPM_HOMEWORKS_11_04_API __declspec(dllimport)
#endif


class EquilateralTriangle : public IsoscelesTriangle {
public:
	CPPM_HOMEWORKS_11_04_API EquilateralTriangle(double _a);
};