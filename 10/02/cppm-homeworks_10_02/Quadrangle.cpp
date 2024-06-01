#include <iostream>
#include "Quadrangle.h"

Quadrangle::Quadrangle(double _a, double _b, double _c, double _d, double _A, double _B, double _C, double _D) : a(_a), b(_b), c(_c), d(_d), A(_A), B(_B), C(_C), D(_D) {
	name = "Четырехугольник";
}
double Quadrangle::get_a() { return a; }
double Quadrangle::get_b() { return b; }
double Quadrangle::get_c() { return c; }
double Quadrangle::get_d() { return d; }
double Quadrangle::get_A() { return A; }
double Quadrangle::get_B() { return B; }
double Quadrangle::get_C() { return C; }
double Quadrangle::get_D() { return D; }
void Quadrangle::print_info() {
	std::cout << get_name() << ":" << std::endl;
	std::cout << "Стороны: " << "a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << std::endl;
	std::cout << "Углы: " << "A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << std::endl;
}