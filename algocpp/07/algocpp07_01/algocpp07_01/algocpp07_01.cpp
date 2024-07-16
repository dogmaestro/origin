#include <iostream>
#include <fstream>

void dfs(int vertex, int** graph, bool* visited, int n) {
	visited[vertex] = true;
	std::cout << vertex + 1 << " ";

	for (int i = 0; i < n; ++i) {
		if (graph[vertex][i] && !visited[i]) {
			dfs(i, graph, visited, n);
		}
	}
}

void dfs(int** graph, bool* visited, int n) {
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			dfs(i, graph, visited, n);
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

	std::cout << "Порядок обхода вершин: ";

	dfs(graph, visited, n);	

	std::cout << std::endl;

	for (int i = 0; i < n; ++i) {
		delete[] graph[i];
	}
	delete[] graph;
	delete[] visited;

	return 0;
}
