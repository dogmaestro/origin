#include <iostream>
#include <windows.h>

int function(std::string str, int forbidden_length) {
    int length = str.length();
    
    if (length == forbidden_length) {
        throw std::string("bad_length");
    }
    else {
        return length;
    }
}


int main() {
    SetConsoleCP(1251);
   // SetConsoleOutputCP(1251);
    int forbidden_length;        
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;

    try {
        while (true) {
            std::string str;
            std::cout << "Введите слово: ";
            std::cin >> str;
            std::cout << std::endl;
            std::cout << "Длина слова """ << str << """ равна " << function(str, forbidden_length) << std::endl;
        }
    }
    catch (std::string ex) {
        if (ex == "bad_length") {
            std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
            return 0;
        }
        else {
            throw;
        }
    }
    return 0;
}
