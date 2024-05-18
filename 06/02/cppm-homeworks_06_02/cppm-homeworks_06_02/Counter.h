#pragma once

class Counter {
public:
	void inc();
	void dec();
	void show();

	Counter(int count = 1);

private:
	int count;
};