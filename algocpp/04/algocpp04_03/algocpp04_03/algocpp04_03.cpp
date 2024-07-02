#include <iostream>

void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size) {

	for (int i = 1; i < logical_size; ++i) {
		arr[i - 1] = arr[i];
	}
	--logical_size;

	if (actual_size >=3 && logical_size <= actual_size / 3) {
		actual_size /= 3;
		int* new_arr = new int[actual_size];
		for (int i = 0; i < logical_size; ++i) {
			new_arr[i] = arr[i];
		}
		delete[] arr;
		arr = new_arr;
	}
}

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
	for (int i = 0; i < logical_size; ++i) {
		std::cout << arr[i] << " ";
	}

	for (int i = logical_size; i < actual_size; ++i) {
		std::cout << "_ ";
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
		std::string yesno;
		do {
			std::cout << "Удалить первый элемент? ";
			std::cin >> yesno;
		} while ((yesno != "да") && (yesno != "нет"));
		if (yesno == "нет") {
			std::cout << "Спасибо! Ваш динамический массив: ";
			print_dynamic_array(arr, logical_size, actual_size);
			break;
		}
		else {
			if (logical_size > 0) {
				remove_dynamic_array_head(arr, logical_size, actual_size);
				std::cout << "Динамический массив: ";
				print_dynamic_array(arr, logical_size, actual_size);
			}
			else {
				std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания! ";
				break;
			}
		}
	};

	delete[] arr;
	std::cout << std::endl;
	return 0;
}
