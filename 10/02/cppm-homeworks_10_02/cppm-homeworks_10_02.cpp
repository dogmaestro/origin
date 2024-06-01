#include <iostream>
#include "Figure.h"
#include "Triangle.h"
#include "RectangularTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhomb.h"

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
	figures[4] = new Quadrangle{10, 20, 30, 40, 50, 60, 70, 80};
	figures[5] = new Rectangle{ 10, 20 };
	figures[6] = new Square{ 20 };
	figures[7] = new Parallelogram{ 20, 30, 30, 40 };
	figures[8] = new Rhomb{ 30, 30, 40 };

	for (int i = 0; i < 9; i++) {
		print_info(figures[i]);
		std::cout << std::endl;
		delete figures[i];
	}
	
    system("pause");	

	return 0;
}
