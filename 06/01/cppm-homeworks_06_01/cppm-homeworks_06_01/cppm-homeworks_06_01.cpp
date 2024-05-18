#include <iostream>
#include "functions.h"

int main() {
    double x, y;
    int operation;
    std::cout << "Введите первое число: ";
    std::cin >> x;
    std::cout << "Введите второе число: ";
    std::cin >> y;
    std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    std::cin >> operation;
    switch(operation) {
        case 1:
            std::cout << x << " плюс "  << y << " = " << add(x, y) << std::endl;
            break;
        case 2:
            std::cout << x << " минус " << y << " = " << sub(x, y) << std::endl;
            break;
        case 3:
            std::cout << x << " умножить на " << y << " = " << mult(x, y) << std::endl;
            break;
        case 4:
            std::cout << x << " разделить на " << y << " = " << divide(x, y) << std::endl;
            break;
        case 5:
            std::cout << x << " в степени " << y << " = " << power(x, y) << std::endl;
            break;
    }

    return 0;
}
