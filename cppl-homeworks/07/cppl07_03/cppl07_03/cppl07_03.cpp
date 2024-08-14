#include <iostream>
#include <stdexcept>

template <class T>
class smart_array {
public:
	smart_array(size_t initial_capacity = 10)
		: capacity_(initial_capacity), size_(0), data(new T[initial_capacity]) {}

	~smart_array() {
		delete[] data;
	}

	void push_back(T value) {
		size_++;
		if (size_ == capacity_) {
			resize();
		}
		data[size_ - 1] = value;
	}

	T at(size_t index) const {
		if (index >= size_) {
			throw std::out_of_range("Index out of range");
		}
		return data[index];
	}

	size_t size() const {
		return size_;
	}

	size_t capacity() const {
		return capacity_;
	}

private:
	size_t capacity_;
	size_t size_;
	T* data;

	void resize() {
		size_t new_capacity = capacity_ * 2;
		T* new_data = new T[new_capacity];
		for (size_t i = 0; i < size_; ++i) {
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;
		capacity_ = new_capacity;
	}
};

int main() {
	try {
		smart_array<int> arr(5);
		arr.push_back(1);
		arr.push_back(4);
		arr.push_back(155);
		arr.push_back(14);
		arr.push_back(15);

		std::cout << arr.at(1) << " " << arr.size() << " " << arr.capacity() << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
