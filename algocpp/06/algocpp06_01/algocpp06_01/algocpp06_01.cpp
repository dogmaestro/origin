#include <iostream>
#include <string>

int simple_string_hash(std::string s) {
    int hash = 0;
    for (char c : s) {
        hash += static_cast<int>(c);
    }
    return hash;
}

int main() {
    std::string s;
    do {
        std::cout << "Введите строку: ";
        std::cin >> s;
        std::cout << "Наивный хэш строки " << s << " = " << simple_string_hash(s) << std::endl;
    } while (s != "exit");
    return 0;
}
