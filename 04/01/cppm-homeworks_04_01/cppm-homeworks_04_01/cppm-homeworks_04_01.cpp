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
private:
	std::string city;
	std::string street;
	int house;
	int flat;
};


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

	    std::ofstream outFile("out.txt");
	    if (outFile.is_open()) {
            outFile << size << std::endl;
		    for (int i = size - 1; i >= 0; --i) {
				outFile << arr[i].get_output_address() << std::endl;
		    }
			outFile.close();
			inFile.close();
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
