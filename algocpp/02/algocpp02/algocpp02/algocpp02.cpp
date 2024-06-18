#include <iostream>

int binarySearch(int arr[], int size, int refPoint) {
	if (arr[size - 1] <= refPoint) {
		return 0;
	}
	else if (arr[0] > refPoint) {
		return size;
	}
	else {
		int result = -1;
		int left = 0;
		int right = size - 1;
		while (left <= right) {
			int middle = left + (right - left) / 2;

			if (arr[middle] <= refPoint) {
				left = middle + 1;
			}
			else {
				result = middle;
				right = middle - 1;
			}
		}

		return size - result;
	}
}

int main()
{
	int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	int refPoint;
	int size = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Введите точку отсчёта: ";
	std::cin >> refPoint;
	int result = binarySearch(arr, size, refPoint);
	std::cout << "Количество элементов в массиве больших, чем " << refPoint << ": " << result;
	return 0;
}