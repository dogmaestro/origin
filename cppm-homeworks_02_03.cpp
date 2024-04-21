#include <iostream>

struct Address {
	std::string city;
	std::string street;
	std::string house;
	std::string flat;
	std::string index;
};

void print(Address address) {
	std::cout << "Город: " << address.city << std::endl;
	std::cout << "Улица: " << address.street << std::endl;
	std::cout << "Номер дома: " << address.house << std::endl;
	std::cout << "Номер квартиры: " << address.flat << std::endl;
	std::cout << "Индекс: " << address.index << std::endl;
	std::cout << std::endl;
}

int main() {
	Address address = {"Москва", "Арбат", "12", "8", "123456"};
	print(address);

	address = {"Ижевск", "Пушкина", "59", "143", "953769"};
	print(address);
	
	return 0;
}
