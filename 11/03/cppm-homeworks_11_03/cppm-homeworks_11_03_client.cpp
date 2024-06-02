
#include <iostream>
#include "Leaver.h"

int main() {
    Leaver leaver;
    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << leaver.leave(name) << std::endl;
    system("pause");	
}
