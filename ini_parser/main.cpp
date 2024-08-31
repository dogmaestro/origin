#include <string>
#include <stdexcept>
#include <iostream>
#include "ini_parser.h"

int main() {
	try {

		ini_parser parser("example.ini");
		auto value = parser.get_value<std::string>("Section2.var2");
		std::cout << "Section2.var2=" << value << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Ошибка: " << e.what() << std::endl;
	}
	return 0;
}