#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {

	for (int i = 0; i < logical_size; ++i) {
		std::cout << arr[i] << " ";
	}

	for (int i = logical_size; i < actual_size; ++i) {
		std::cout << "_ ";;
	}

	std::cout << std::endl;
}

int main() {
	int* arr;
	int logical_size;
	int actual_size;

	std::cout << "Введите фактический размер массива: ";
	std::cin >> actual_size;

	std::cout << "Введите логический размер массива: ";
	std::cin >> logical_size;

	if (actual_size < logical_size) {
		std::cout << "Ошибка! Логический размермассива не может превышать фактический!" << std::endl;
		return -1;
	}

	arr = new int[actual_size];

	for (int i = 0; i < logical_size; ++i) {
		std::cout << "Введите arr[" << i << "]: ";
		std::cin >> arr[i];
	}

	std::cout << "Динамический массив: ";
	print_dynamic_array(arr, logical_size, actual_size);

	delete[] arr;

	return 0;
}