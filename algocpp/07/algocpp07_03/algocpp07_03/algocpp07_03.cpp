#include <iostream>
#include <fstream>

bool dfs(int vertex, int** graph, bool* visited, int n, int prev) {
	visited[vertex] = true;
	for (int i = 0; i < n; ++i) {
		if (graph[vertex][i]) {
			if (!visited[i]) {
				if (dfs(i, graph, visited, n, vertex)) {
					return true;
				}
			}
			else {
				if ((prev != -1) && prev != i) {
					return true;
				}
			}
		}
	}
	return false;
}

bool is_cyclic(int** graph, bool* visited, int n) {
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			if (dfs(i, graph, visited, n, -1)) {
				return true;
			}
		}
	}
	return false;
}

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

	bool* visited = new bool[n]();



	if (is_cyclic(graph, visited, n)) {
		std::cout << "В графе есть цикл!";
	}
	else {
		std::cout << "В графе нет циклов";
	}

	std::cout << std::endl;

	for (int i = 0; i < n; ++i) {
		delete[] graph[i];
	}
	delete[] graph;
	delete[] visited;

	return 0;
}
