#include <iostream>
#include <vector>
#include <string>

class big_integer {
private:
	std::vector<int> digits;
public:
	big_integer() {};
	big_integer(const std::string& number) {
		if (number.empty()) {
			digits.push_back(0);
		}
		else {
			for (size_t i = number.size(); i > 0; --i) {
				if (isdigit(number[i - 1])) {
					digits.push_back(std::stoi(std::string(1, number[i - 1])));
				}
			}
		}
	}

	big_integer(big_integer&& other) noexcept : digits(std::move(other.digits)) {}

	big_integer& operator=(big_integer&& other) noexcept {
		if (this != &other) {
			digits = std::move(other.digits);
		}
		return *this;
	}

	big_integer operator+(const big_integer& other) const {
		big_integer result;
		int carry = 0;
		size_t n = std::max(digits.size(), other.digits.size());
		for (auto i = 0; (i < n) || (carry > 0); ++i) {
			int sum = carry;
			if (i < digits.size()) {
				sum += digits[i];
			}
			if (i < other.digits.size()) {
				sum += other.digits[i];
			}
			result.digits.push_back(sum % 10);
			carry = sum / 10;
		}
		return result;
	}

	big_integer operator*(const int& number) const {
		big_integer result;
		int carry = 0;
		size_t n = digits.size();
		for (size_t i = 0; (i < n) || (carry > 0); ++i) {
			int mul = carry;
			if (i < digits.size()) {
				mul += digits[i] * number;
			}
			result.digits.push_back(mul % 10);
			carry = mul / 10;
		}
		return result;
	}

	bool operator==(const big_integer& other) const {
		return digits == other.digits;
	}

	friend std::ostream& operator<<(std::ostream& os, const big_integer& number) {
		for (size_t i = number.digits.size(); i > 0; --i) {
			os << number.digits[i - 1];
		}
		return os;
	}
};

int main() {
	auto number1 = big_integer("114575");
	auto number2 = big_integer("78524");
	auto result = number1 + number2;
	std::cout << result << std::endl; 

	auto number3 = std::move(result);
	std::cout << number3 << std::endl;

	return 0;
}
