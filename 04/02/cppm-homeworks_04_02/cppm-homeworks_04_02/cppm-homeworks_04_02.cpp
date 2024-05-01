#include <iostream>
#include <fstream>
#include <string>

class Address {
public:
	Address(std::string city, std::string street, int house, int flat) {
		this->city = city;
		this->street = street;
		this->house = house;
		this->flat = flat;
	}
	Address() {}
	std::string get_output_address() {
		return this->city + ", " + this->street + ", " + std::to_string(this->house) + ", " + std::to_string(this->flat);
	}
	std::string getCity() {
		return city;
	}
private:
	std::string city;
	std::string street;
	int house;
	int flat;
};

void sort(Address* addresses, int size) {
    for (int i = 0; i < size; i++) {
		int nsorted = size - i;
		for (int j = 0; j < nsorted - 1; j++) {
			if (addresses[j].getCity() > addresses[j + 1].getCity()) {
				std::swap(addresses[j], addresses[j + 1]);
			}
		}
	}
}

int main() {
	std::ifstream inFile("in.txt");
	if (inFile.is_open()) {
		int size;
		inFile >> size;

		Address* arr = new Address[size];
		for (int i = 0; i < size; ++i) {
			std::string city;
			std::string street;
			int house;
			int flat;

			inFile >> city;
			inFile >> street;
			inFile >> house;
			inFile >> flat;

			Address address(city, street, house, flat);
			arr[i] = address;
		}

		sort(arr, size);

	    std::ofstream outFile("out.txt");
	    if (outFile.is_open()) {
            outFile << size << std::endl;
		    for (int i = 0; i < size; i++) {
				outFile << (arr[i]).get_output_address() << std::endl;
		    }
		    outFile.close();
		    inFile.close();
		    std::cout << "OK" << std::endl;
		}
		else {
            std::cout << "Failed to open output file!" << std::endl;
		}

		delete[] arr;

	}
	else {
		std::cout << "Failed to open input file!" << std::endl;
	}
	return 0;
}
