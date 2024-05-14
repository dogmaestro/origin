#include <iostream>

class Figure {
public:
	Figure() {
		name = "Фигура";
		sides_count = 0;
	}

	int get_sides_count() { return sides_count; }

	virtual bool check() { return (sides_count == 0 ? true : false); }

	virtual void print_info() {
		std::cout << name << ":" << std::endl;
		std::cout << (check() ? "Правильная" : "Неправильная") << std::endl;
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
	}
	
protected:
	int sides_count;
	std::string name;
};

class Triangle : public Figure {
public:
	Triangle(double _a, double _b, double _c, double _A, double _B, double _C) : a(_a), b(_b), c(_c), A(_A), B(_B), C(_C) {
		name = "Треугольник";
		sides_count = 3;
	}

	double get_a() { return a; }
	double get_b() { return b; }
	double get_c() { return c; }
	double get_A() { return A; }
	double get_B() { return B; }
	double get_C() { return C; }

	bool check() override { return ((sides_count == 3 && (get_A() + get_B() + get_C() == 180)) ? true : false); }

	void print_info() override {
		Figure::print_info();
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

	bool check() override { return Triangle::check() && get_C() == 90 ? true : false; }
};

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(double _a, double _b, double _A, double _B) :
		Triangle(_a, _b, _a, _A, _B, _A) {
		name = "Равнобедренный треугольник";
	}

	bool check() override { return Triangle::check() && get_a() == get_c() && get_A() == get_C() ? true : false; }
};

class EquilateralTriangle : public IsoscelesTriangle {
public:
	EquilateralTriangle(double _a) :
		IsoscelesTriangle(_a, _a, 60, 60) {
		name = "Равносторонний треугольник";
	}

	bool check() override { return IsoscelesTriangle::check() && get_a() == get_b() && get_A() == 60 && get_B() == 60 ? true : false; }
};

class Quadrangle : public Figure {
public:
	Quadrangle(double _a, double _b, double _c, double _d, double _A, double _B, double _C, double _D) : a(_a), b(_b), c(_c), d(_d), A(_A), B(_B), C(_C), D(_D) {
		name = "Четырехугольник";
		sides_count = 4;
	}

	double get_a() { return a; }
	double get_b() { return b; }
	double get_c() { return c; }
	double get_d() { return d; }
	double get_A() { return A; }
	double get_B() { return B; }
	double get_C() { return C; }
	double get_D() { return D; }

	bool check() override { return sides_count == 4 && (get_A() + get_B() + get_C() + get_D() == 360) ? true : false; }

	void print_info() override {
		Figure::print_info();
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

	bool check() override { return Quadrangle::check() && get_a() == get_c() && get_b() == get_d() && get_A() == 90 && get_B() == 90 && get_C() == 90 && get_D() == 90 ? true : false; }

};

class Square : public Rectangle {
public:
	Square(double _a) :
		Rectangle(_a, _a) {
		name = "Квадрат";
	}

	bool check() override { return Rectangle::check() && get_a() == get_b() && get_b() == get_c() && get_c() == get_d() ? true : false; }

};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(double _a, double _b, double _A, double _B) :
		Quadrangle(_a, _b, _a, _b, _A, _B, _A, _B) {
		name = "Параллелограмм";
	}

	bool check() override { return Quadrangle::check() && get_a() == get_c() && get_b() == get_d() && get_A() == get_C() && get_B() == get_D() ? true : false; }

};

class Rhomb : public Parallelogram {
public:
	Rhomb(double _a, double _A, double _B) :
		Parallelogram(_a, _a, _A, _B) {
		name = "Ромб";
	}

	bool check() override { return Parallelogram::check() && get_b() == get_c() ? true : false; }

};


int main()
{
	Figure* figures[11];

	figures[0] = new Figure;
	figures[1] = new Triangle{10, 20, 30, 50, 60, 70};
	figures[2] = new RectangularTriangle{ 10, 20, 30, 50, 60 };
	figures[3] = new RectangularTriangle{ 10, 20, 30, 50, 40 };
	figures[4] = new IsoscelesTriangle{ 10, 20, 50, 60 };
	figures[5] = new EquilateralTriangle{ 30 };
	figures[6] = new Quadrangle{ 10, 20, 30, 40, 50, 60, 70, 80 };
	figures[7] = new Rectangle{ 10, 20 };
	figures[8] = new Square{ 20 };
	figures[9] = new Parallelogram{ 20, 30, 30, 40 };
	figures[10] = new Rhomb{ 30, 30, 40 };

	for (int i = 0; i < 11; i++) {
		figures[i]->print_info();
		std::cout << std::endl;
		delete figures[i];
	}

	return 0;
}
