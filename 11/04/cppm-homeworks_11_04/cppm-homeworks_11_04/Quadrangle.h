#pragma once
#include "Figure.h"

#ifdef CPPM_HOMEWORKS_11_04_EXPORTS
#define CPPM_HOMEWORKS_11_04_API __declspec(dllexport)
#else
#define CPPM_HOMEWORKS_11_04_API __declspec(dllimport)
#endif

class Quadrangle : public Figure {
public:
	CPPM_HOMEWORKS_11_04_API Quadrangle(double _a, double _b, double _c, double _d, double _A, double _B, double _C, double _D);
	CPPM_HOMEWORKS_11_04_API double get_a();
	CPPM_HOMEWORKS_11_04_API double get_b();
	CPPM_HOMEWORKS_11_04_API double get_c();
	CPPM_HOMEWORKS_11_04_API double get_d();
	CPPM_HOMEWORKS_11_04_API double get_A();
	CPPM_HOMEWORKS_11_04_API double get_B();
	CPPM_HOMEWORKS_11_04_API double get_C();
	CPPM_HOMEWORKS_11_04_API double get_D();
	CPPM_HOMEWORKS_11_04_API void print_info() override;
protected:
	double a;
	double b;
	double c;
	double d;
	double A;
	double B;
	double C;
	double D;
};

