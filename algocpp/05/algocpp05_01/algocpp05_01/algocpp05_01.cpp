#include <iostream>
#include <string>
#include <cmath>

int getParentIndex(int index) {
	if (index % 2 == 0) {
		return (index - 2) / 2;
	}
	else {
		return (index - 1) / 2;
	}
}

void print_element(int* arr, int index, int level) {
	std::string side = (index == 0 ? "root" : (index % 2 == 0 ? "right" : "left"));
	std::string parent = (index == 0 ? " " : "(" + std::to_string(arr[getParentIndex(index)]) + ") ");
	std::cout << level << " ";
	std::cout << side;
	std::cout << parent;
	std::cout << arr[index];
}

void print_pyramid(int* arr, int size) {
	std::cout << "Исходный массив: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Пирамида:" << std::endl;
	int height = std::floor(log2(size + 1)) + 1;
	for (int level = 0; level < height; ++level) {
		int level_size = pow(2, level);
		int start_index = level_size - 1;
		int end_index = start_index + level_size - 1;
		for (int index = start_index; index <= end_index && index < size; ++index) {
			print_element(arr, index, level);
			std::cout << std::endl;
		}
	}
}

int main() {
	{
		int array[] = { 1, 3, 6, 5, 9, 8 };
		int size = sizeof(array) / sizeof(array[0]);
		print_pyramid(array, size);
	}

	{
		int array[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
		int size = sizeof(array) / sizeof(array[0]);
		print_pyramid(array, size);
	}

	{
		int array[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
		int size = sizeof(array) / sizeof(array[0]);
		print_pyramid(array, size);
	}

	return 0;
}