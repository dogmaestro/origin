#include <iostream>
#include <stdexcept>

class smart_array {
public:
	smart_array(size_t size_ = 10)
		: last_index(0), size(size_), data(new int[size_]()) {}

	~smart_array() {
		delete[] data;
	}

	void add_element(int value) {
		if (last_index >= size ) {
			throw std::overflow_error("Out of range");
		}
		data[last_index] = value;
		last_index++;
	}

	int get_element(size_t index) const {
		if (index >= size || index < 0) {
			throw std::out_of_range("Index out of range");
		}
		return data[index];
	}

private:
	size_t last_index;
	size_t size;
	int* data;
};

int main() {
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
