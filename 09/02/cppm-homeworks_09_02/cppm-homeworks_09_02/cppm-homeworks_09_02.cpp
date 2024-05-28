#include <iostream>

// наибольший общий делитель
int gcd(int a, int b) {
	if (a == 0)
		return b;
	if (b == 0)
		return a;

	if (a == b)
		return a;

	if (a > b)
		return gcd(a - b, b);
	return gcd(a, b - a);
}

class Fraction
{
private:
	int numerator_;
	int denominator_;
	double getDifference(Fraction other) {
		return static_cast<double>(numerator_ * other.denominator_ - denominator_ * other.numerator_) / (denominator_ * other.denominator_);
	}


public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	bool operator==(Fraction other) {
		return  getDifference(other) == 0;
	}
	bool operator!=(Fraction other) {
		return !(*this == other);
	}
	bool operator<=(Fraction other) {
		return getDifference(other) <= 0;
	}
	bool operator>=(Fraction other) {
		return getDifference(other) >= 0;
	}

	bool operator<(Fraction other) {
		return !(*this >= other);
	}
	bool operator>(Fraction other) {
		return !(*this <= other);
	}

	friend std::ostream& operator<<(std::ostream& left, Fraction right);

	Fraction& operator=(const Fraction& other) {
		numerator_ = other.numerator_;
		denominator_ = other.denominator_;
		return *this;
	}

	Fraction operator+(Fraction other) {
		int newDenominator = (denominator_ * other.denominator_) / gcd(std::abs(denominator_), std::abs(other.denominator_));
		int newNumerator = numerator_ * (newDenominator / denominator_) + other.numerator_ * (newDenominator / other.denominator_);
		int newgcd = gcd(std::abs(newNumerator), std::abs(newDenominator));
		newDenominator /= newgcd;
		newNumerator /= newgcd;
		return Fraction(newNumerator, newDenominator);
	}

	Fraction operator-(Fraction other) {
		return *this + Fraction(-other.numerator_, other.denominator_);
	}

	Fraction operator*(Fraction other) {
		int newDenominator = (denominator_ * other.denominator_);
		int newNumerator = (numerator_ * other.numerator_);
		int newgcd = gcd(std::abs(newNumerator), std::abs(newDenominator));
		newDenominator /= newgcd;
		newNumerator /= newgcd;
		return Fraction(newNumerator, newDenominator);
	}

	Fraction operator/(Fraction other) {
		return *this * Fraction(other.denominator_, other.numerator_);
	}

	Fraction& operator++() {
		Fraction tmpFraction = *this + Fraction(1, 1);
		numerator_ = tmpFraction.numerator_;
		denominator_ = tmpFraction.denominator_;
		return *this;
	}

	Fraction& operator--() {
		Fraction tmpFraction = *this - Fraction(1, 1);
		numerator_ = tmpFraction.numerator_;
		denominator_ = tmpFraction.denominator_;
		return *this;
	}

	Fraction operator++(int) {
		Fraction tmpFraction = *this;
		++(*this);
		return tmpFraction;
	}

	Fraction operator--(int) {
		Fraction tmpFraction = *this;
		--(*this);
		return tmpFraction;
	}

};

std::ostream& operator<<(std::ostream& left, Fraction right) {
	if (right.numerator_ == 0 || right.denominator_ == 1) {
		left << right.numerator_;
	}
	else {
		left << right.numerator_ << "/" << right.denominator_;
	}
	return left;
}

int main() {
	int numerator1, denominator1, numerator2, denominator2;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> numerator1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denominator1;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numerator2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denominator2;

	Fraction f1(numerator1, denominator1);
	Fraction f2(numerator2, denominator2);

	std::cout << f1 << " + " << f2 << " = " << f1 + f2 << std::endl;
	std::cout << f1 << " - " << f2 << " = " << f1 - f2 << std::endl;
	std::cout << f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
	std::cout << f1 << " / " << f2 << " = " << f1 / f2 << std::endl;

	std::cout << "++" << f1 << " * " << f2 << " = ";
	std::cout << ++f1 * f2 << std::endl;
	std::cout << "Значение дроби 1 = " << f1 << std::endl;

	std::cout << f1 << "-- * " << f2 << " = ";
	std::cout << f1-- * f2 << std::endl;
	std::cout << "Значение дроби 1 = " << f1 << std::endl;
	

	return 0;
}