#pragma once
#include "Figure.h"

class Quadrangle : public Figure {
public:
	Quadrangle(double _a, double _b, double _c, double _d, double _A, double _B, double _C, double _D);
	double get_a();
	double get_b();
	double get_c();
	double get_d();
	double get_A();
	double get_B();
	double get_C();
	double get_D();
	void print_info() override;
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

