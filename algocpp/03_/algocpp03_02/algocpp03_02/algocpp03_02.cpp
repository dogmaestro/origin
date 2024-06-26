#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void quick_sort(int* arr, int size) {
    int low = 0;
    int high = size - 1;

    if (low < high) {
        int p = partition(arr, low, high);
        quick_sort(arr + low, p - low + 1);
        quick_sort(arr + p + 1, high - p);
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

        quick_sort(arr, arrSize);

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

        quick_sort(arr, arrSize);

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

        quick_sort(arr, arrSize);

        std::cout << "Отсортированный массив: ";
        for (int i = 0; i < arrSize; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl << std::endl;
    }

    return 0;
}