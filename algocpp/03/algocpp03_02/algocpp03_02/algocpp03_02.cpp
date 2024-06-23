#include <iostream>

int fib(int n, int* cacheArray) {
    if (n <= 1)
        return n;

    if (cacheArray[n] != -1) {
        return cacheArray[n];
    }

    cacheArray[n] = fib(n - 1, cacheArray) + fib(n - 2, cacheArray);
    return cacheArray[n];
}

int main() {
    int n;
    std::cout << "Введите число: ";
    std::cin >> n;

    int* cacheArray = new int[n + 1];
    for (int i = 0; i <= n; i++) {
        cacheArray[i] = -1;
    }

    std::cout << "Числа Фибоначчи: ";
    for (int i = 0; i <= n; i++) {
        std::cout << fib(i, cacheArray) << " ";
    }

    delete[] cacheArray;

    return 0;
}