#include <iostream>
#include <fstream>

int main() {

	std::ifstream infile("input.txt");

	if (!infile) {
		std::cerr << "Ошибка открытия файла input.txt";
		return -1;
	}

	int n;
	infile >> n;

	int** graph = new int* [n];
	for (int i = 0; i < n; ++i) {
		graph[i] = new int[n];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			infile >> graph[i][j];
		}
	}
	infile.close();

	std::cout << "Текстовый вид орграфа:"  << std::endl;

	for (int i = 0; i < n; ++i) {
		bool hasOutgoingEdge = false;
		std::cout << i + 1 << ":";
		for (int j = 0; j < n; ++j) {
			if (graph[i][j] == 1) {
				std::cout << " " << j + 1;
				hasOutgoingEdge = true;
			}
		}
		if (!hasOutgoingEdge) {
			std::cout << " нет";
		}
		std::cout << std::endl;
	}


	for (int i = 0; i < n; ++i) {
		delete[] graph[i];
	}
	delete[] graph;

	return 0;
}
