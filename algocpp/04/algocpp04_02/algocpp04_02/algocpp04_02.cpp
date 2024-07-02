#include <iostream>

void append_to_dynamic_array(int* &arr, int value, int& logical_size, int& actual_size) {

	if (logical_size == actual_size) {
		actual_size *= 2;
		int* new_arr = new int[actual_size];
		for (int i = 0; i < logical_size; i++) {
			new_arr[i] = arr[i];
		}

		delete[] arr;
		arr = new_arr;
	}
	arr[logical_size] = value;
	logical_size++;
}

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
	
	while (true) {
		std::cout << "Введите фактический размер массива: ";
		std::cin >> actual_size;

		std::cout << "Введите логический размер массива: ";
		std::cin >> logical_size;

		if (actual_size < logical_size) {
			std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
			return -1;
		}
		else {
			break;
		}
	}

	arr = new int[actual_size];

	for (int i = 0; i < logical_size; ++i) {
		std::cout << "Введите arr[" << i << "]: ";
		std::cin >> arr[i];
	}
	std::cout << "Динамический массив: ";
	print_dynamic_array(arr, logical_size, actual_size);

	while (true) {
		int value;
		std::cout << "Введите элемент для добавления: ";
		std::cin >> value;
		if (value == 0) {
			std::cout << "Спасибо! Ваш массив: ";
			print_dynamic_array(arr, logical_size, actual_size);
			break;
		}
		else {
			append_to_dynamic_array(arr, value, logical_size, actual_size);
			std::cout << "Динамический массив: ";
			print_dynamic_array(arr, logical_size, actual_size);
		}
	};

	delete[] arr;
	std::cout << std::endl;
	return 0;
}
