#include <iostream>
#include <fstream>

void dfs(int vertex, int** graph, bool* visited, int n, int* order, int& orderIndex) {
	visited[vertex] = true;
	for (int i = 0; i < n; ++i) {
		if (graph[vertex][i]) {
			if (!visited[i]) {
				dfs(i, graph, visited, n, order, orderIndex);
			}
		}
	}
	order[orderIndex--] = vertex;
}

void top_sort(int** graph, bool* visited, int n, int* order, int& orderIndex) {
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			dfs(i, graph, visited, n, order, orderIndex);
		}
	}
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
	int* order = new int[n];
	int orderIndex = n - 1;


	top_sort(graph, visited, n, order, orderIndex);

	std::cout << "Топологический порядок вершин: ";

	for (int i = 0; i < n; ++i) {
		std::cout << order[i] + 1 << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < n; ++i) {
		delete[] graph[i];
	}
	delete[] graph;
	delete[] visited;
	delete[] order;

	return 0;
}
