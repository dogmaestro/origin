
#include <iostream>
#include "Greeter.h"

int main() {
    Greeter greeter;
    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << greeter.greet(name);
}
