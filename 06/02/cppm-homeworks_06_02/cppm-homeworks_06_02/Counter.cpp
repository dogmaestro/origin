#include <iostream>
#include "Counter.h"

void Counter::inc() {
	count++;
}

void Counter::dec() {
	count--;
}

void Counter::show() {
	std::cout << count << std::endl;
}

Counter::Counter(int count) { this->count = count; }
