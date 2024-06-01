#include <iostream>

int main()
{
	std::string name;

	std::cout << "Введите имя: ";
	std::cin >>  name;
	std::cout << "Здравствуйте, " << name << "!" << std::endl;
    system("pause");	
	
	return 0;
}