#pragma once
#include "Parallelogram.h"

#ifdef CPPM_HOMEWORKS_11_04_EXPORTS
#define CPPM_HOMEWORKS_11_04_API __declspec(dllexport)
#else
#define CPPM_HOMEWORKS_11_04_API __declspec(dllimport)
#endif

class Rhomb : public Parallelogram {
public:
	CPPM_HOMEWORKS_11_04_API Rhomb(double _a, double _A, double _B);
};