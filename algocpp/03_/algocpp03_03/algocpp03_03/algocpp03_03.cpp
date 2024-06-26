#include <iostream>
#define MIN 10
#define MAX 24

void count_sort(int* arr, int size) {
    int min = MIN;

    for (int i = 0; i < size; ++i) {
        arr[i] -= min;
    }

    int max = MAX - min;

    int* counter = new int[max + 1]();

    for (int i = 0; i < size; ++i) {
        counter[arr[i]]++;
    }

    int* output = new int[size];

    int c = 0;
    for (int num = 0; num < max + 1; num++) {
        int count = counter[num];
        for (int i = 0; i < count; i++) {
            output[c] = num + min;
            c++;
        }
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }

    delete[] counter;
    delete[] output;

}

int main() {

    {
        int arr[] = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
        int arrSize = sizeof(arr) / sizeof(arr[0]);

        std::cout << "Исходный массив: ";
        for (int i = 0; i < arrSize; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        count_sort(arr, arrSize);

        std::cout << "Отсортированный массив: ";
        for (int i = 0; i < arrSize; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl << std::endl;
    }

    {
        int arr[] = { 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
        int arrSize = sizeof(arr) / sizeof(arr[0]);

        std::cout << "Исходный массив: ";
        for (int i = 0; i < arrSize; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        count_sort(arr, arrSize);

        std::cout << "Отсортированный массив: ";
        for (int i = 0; i < arrSize; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl << std::endl;
    }

    {
        int arr[] = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };
        int arrSize = sizeof(arr) / sizeof(arr[0]);

        std::cout << "Исходный массив: ";
        for (int i = 0; i < arrSize; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        count_sort(arr, arrSize);

        std::cout << "Отсортированный массив: ";
        for (int i = 0; i < arrSize; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl << std::endl;
    }

    return 0;
}