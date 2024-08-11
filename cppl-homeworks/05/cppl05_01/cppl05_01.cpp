#include <iostream>
#include <vector>

template <typename T>
T square(const T& value) {
	return value * value;
}

template <typename T>
std::vector<T> square(const std::vector<T>& vec) {
	std::vector<T> result;
	result.reserve(vec.size());
	for (const auto& elem : vec) {
		result.push_back(square(elem));
	}
	return result;
}

int main() {

	int num = 4;
	std::cout << "[IN]: " << num << std::endl;
	std::cout << "[OUT]: " << square(num) << std::endl;

	std::vector<int> vec = { -1, 4, 8 };
	std::vector<int> squaredVec = square(vec);

	std::cout << "[IN]: ";
	for (const auto& elem : vec) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	std::cout << "[OUT]: ";
	for (const auto& elem : squaredVec) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	return 0;
}
