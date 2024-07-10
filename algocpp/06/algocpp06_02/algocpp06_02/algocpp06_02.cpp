#include <iostream>
#include <string>

long long  real_string_hash(std::string s, int p, int n) {
	long long hash = 0;
	long long pow = 1;
	for (char c : s) {
		hash = (hash + static_cast<int>(c) * pow);
		pow *= p;
	}
	return hash % n;
}

int main() {
	std::string s;
	int p;
	int n;
	std::cout << "Введите p: ";
	std::cin >> p;
	std::cout << "Введите n: ";
	std::cin >> n;
	do {
		std::cout << "Введите строку: ";
		std::cin >> s;
		std::cout << "Хэш строки " << s << " = " << real_string_hash(s, p, n) << std::endl;
	} while (s != "exit");
	return 0;
}
