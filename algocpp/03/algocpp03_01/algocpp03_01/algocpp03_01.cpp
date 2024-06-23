#include <iostream>

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    std::cout << "Введите число: ";
    std::cin >> n;
    std::cout << "Числа Фибоначчи: ";
    for (int i = 0; i <= n; i++) {
        std::cout << fib(i) << " ";
    }
    return 0;
}
