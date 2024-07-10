#include <iostream>
#include <string>

int simple_string_hash(std::string s) {
    int hash = 0;
    for (char c : s) {
        hash += static_cast<int>(c);
    }
    return hash;
}

int find_substring_light_rabin_karp(std::string source, std::string substring) {
    int result;
    int n = source.size();
    int k = substring.size();
    int windowHash;

    if (k > n) {
        return -1;
    }

    int substringHash = simple_string_hash(substring);

    for (int i = 0; i <= n - k; ++i) {
        if (i == 0) {
            windowHash = simple_string_hash(source.substr(0, k));
        }
        else {
            windowHash -= static_cast<int>(source[i - 1]);
            windowHash += static_cast<int>(source[i + k - 1]);
        }
        if (substringHash == windowHash) {
            if (source.substr(i, k) == substring) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    std::string source;
    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> source;
    std::string substring;
    do {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> substring;
        int index = find_substring_light_rabin_karp(source, substring);
        if (index >= 0) {
            std::cout << "Подстрока " << substring << " найдена по индексу " << index << std::endl;
        }
        else {
            std::cout << "Подстрока " << substring << " не найдена" << std::endl;
        }
    } while (substring != "exit");
    return 0;
}
