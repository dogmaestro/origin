#include <iostream>

#define MODE 1

#ifndef MODE
#error Необходимои определить MODE
#endif

#if MODE == 1
double add(double x, double y) {
	return x + y;
}
#endif

int main() {

#if MODE == 0
	std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
	double x, y;
	std::cout << "Работаю в боевом режиме" << std::endl;

	std::cout << "Введите число 1: ";
	std::cin >> x;

	std::cout << "Введите число 2: ";
	std::cin >> y;

	std::cout << "Результат сложения: " << add(x, y);

#else
	std::cout << "Неизвестный режим. Завершение работы" << std::endl;
#endif

	return 0;
}
