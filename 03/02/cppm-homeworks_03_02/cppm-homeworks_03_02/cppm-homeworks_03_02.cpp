#include <iostream>

class Counter {
public:
	void inc() {
		count++;
	}
	void dec() {
		count--;
	}
	void show() {
		std::cout << count << std::endl;
	}

	Counter(int count = 1) { this->count = count; }

private:
	int count;
};

int main()
{
	
	std::string userInput;
	int initialCount;
	Counter counter;

	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::cin >> userInput;
	if (userInput == "да") {
		std::cout << "Введите начальное значение счётчика: ";
		std::cin >> initialCount;
		Counter counter2(initialCount);
		counter = counter2;
	}

	while (true) {
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> userInput;
		if (userInput == "+") {
			counter.inc();
		}
		else if (userInput == "-") {
			counter.dec();
		} else if (userInput == "=") {
			counter.show();
		} else if (userInput == "x") {
			std::cout << "До свидания!" << std::endl;
			return 0;
		}
	};
}
