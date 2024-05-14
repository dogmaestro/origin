#include <iostream>

class Figure {
public:
	Figure() {
		name = "Фигура";
	}
	virtual void print_info() = 0;
protected:
	std::string name;
	std::string get_name() { return name; }
};

class Triangle : public Figure {
public:
	Triangle(double _a, double _b, double _c, double _A, double _B, double _C) : a(_a), b(_b), c(_c), A(_A), B(_B), C(_C) {
		name = "Треугольник";
	}
	double get_a() { return a; }
	double get_b() { return b; }
	double get_c() { return c; }
	double get_A() { return A; }
	double get_B() { return B; }
	double get_C() { return C; }
	void print_info() override {
		std::cout << get_name() << ":" << std::endl;
		std::cout << "Стороны: " << "a=" << get_a() << " b=" << get_b() << " c=" << get_c() << std::endl;
		std::cout << "Углы: " << "A=" << get_A() << " B=" << get_B() << " C=" << get_C() << std::endl;
	}
protected:
	double a;
	double b;
	double c;
	double A;
	double B;
	double C;
};

class RectangularTriangle : public Triangle {
public:
	RectangularTriangle(double _a, double _b, double _c, double _A, double _B) :
		Triangle(_a, _b, _c, _A, _B, 90) {
		name = "Прямоугольный треугольник";
	}
};

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(double _a, double _b, double _A, double _B) :
		Triangle(_a, _b, _a, _A, _B, _A) {
		name = "Равнобедренный треугольник";
	}
};

class EquilateralTriangle : public IsoscelesTriangle {
public:
	EquilateralTriangle(double _a) :
		IsoscelesTriangle(_a, _a, 60, 60) {
		name = "Равносторонний треугольник";
	}
};

class Quadrangle : public Figure {
public:
	Quadrangle(double _a, double _b, double _c, double _d, double _A, double _B, double _C, double _D) : a(_a), b(_b), c(_c), d(_d), A(_A), B(_B), C(_C), D(_D) {
		name = "Четырехугольник";
	}
	double get_a() { return a; }
	double get_b() { return b; }
	double get_c() { return c; }
	double get_d() { return d; }
	double get_A() { return A; }
	double get_B() { return B; }
	double get_C() { return C; }
	double get_D() { return D; }
	void print_info() override {
		std::cout << get_name() << ":" << std::endl;
		std::cout << "Стороны: " << "a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << std::endl;
		std::cout << "Углы: " << "A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << std::endl;
	}
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

class Rectangle : public Quadrangle {
public:
	Rectangle(double _a, double _b) :
		Quadrangle(_a, _b, _a, _b, 90, 90, 90, 90) {
		name = "Прямоугольник";
	}
};

class Square : public Rectangle {
public:
	Square(double _a) :
		Rectangle(_a, _a) {
		name = "Квадрат";
	}
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(double _a, double _b, double _A, double _B) :
		Quadrangle(_a, _b, _a, _b, _A, _B, _A, _B) {
		name = "Параллелограмм";
	}
};

class Rhomb : public Parallelogram {
public:
	Rhomb(double _a, double _A, double _B) :
		Parallelogram(_a, _a, _A, _B) {
		name = "Ромб";
	}
};

void print_info(Figure* figure) {
	figure->print_info();
}

int main()
{
	Figure* figures[9];

	figures[0] = new Triangle{ 10, 20, 30, 50, 60, 70 };
	figures[1] = new RectangularTriangle{ 10, 20, 30, 50, 60 };
	figures[2] = new IsoscelesTriangle{ 10, 20, 50, 60 };
	figures[3] = new EquilateralTriangle{ 30 };
	figures[4] = new Quadrangle{ 10, 20, 30, 40, 50, 60, 70, 80 };
	figures[5] = new Rectangle{ 10, 20 };
	figures[6] = new Square{ 20 };
	figures[7] = new Parallelogram{ 20, 30, 30, 40 };
	figures[8] = new Rhomb{ 30, 30, 40 };

	for (int i = 0; i < 9; i++) {
		print_info(figures[i]);
		std::cout << std::endl;
		delete figures[i];
	}

	return 0;
}
