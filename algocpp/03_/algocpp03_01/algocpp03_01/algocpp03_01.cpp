#include <iostream>

void merge(int* arr, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* leftArr = new int[n1];
	int* rightArr = new int[n2];

	for (int i = 0; i < n1; ++i)
		leftArr[i] = arr[left + i];
	for (int i = 0; i < n2; ++i)
		rightArr[i] = arr[mid + 1 + i];

	int i = 0; 
	int j = 0; 
	int k = left; 

	while (i < n1 && j < n2) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k] = leftArr[i];
			++i;
		}
		else {
			arr[k] = rightArr[j];
			++j;
		}
		++k;
	}

	while (i < n1) {
		arr[k] = leftArr[i];
		++i;
		++k;
	}

	while (j < n2) {
		arr[k] = rightArr[j];
		++j;
		++k;
	}

	delete[] leftArr;
	delete[] rightArr;
}

void merge_sort(int* arr, int arrSize) {
	int left = 0;
	int right = arrSize - 1;

	if (left < right) {
		int mid = left + (right - left) / 2;
		merge_sort(arr + left, mid - left + 1);
		merge_sort(arr + mid + 1, right - mid);
		merge(arr, left, mid, right);
	}
}

int main() {
	{
		int arr[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
		int arrSize = sizeof(arr) / sizeof(arr[0]);

		std::cout << "Исходный массив: ";
		for (int i = 0; i < arrSize; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;

		merge_sort(arr, arrSize);

		std::cout << "Отсортированный массив: ";
		for (int i = 0; i < arrSize; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl << std::endl;
	}

	{
		int arr[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
		int arrSize = sizeof(arr) / sizeof(arr[0]);

		std::cout << "Исходный массив: ";
		for (int i = 0; i < arrSize; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;

		merge_sort(arr, arrSize);

		std::cout << "Отсортированный массив: ";
		for (int i = 0; i < arrSize; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl << std::endl;
	}

	{
		int arr[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
		int arrSize = sizeof(arr) / sizeof(arr[0]);

		std::cout << "Исходный массив: ";
		for (int i = 0; i < arrSize; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;

		merge_sort(arr, arrSize);

		std::cout << "Отсортированный массив: ";
		for (int i = 0; i < arrSize; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl << std::endl;
	}

	return 0;
}