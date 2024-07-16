#include <iostream>
#include <fstream>

void bfs(int start, int** graph, bool* visited, int n) {
	int* queue = new int[n + 1];
	int front = 0, rear = 0;
	queue[rear++] = start - 1;
	visited[start - 1] = true;
	while (front < rear) {
		int current = queue[front++];
		std::cout << current + 1 << " ";

		for (int i = 0; i < n; ++i) {
			if (graph[current][i] && !visited[i]) {
				queue[rear++] = i;
				visited[i] = true;
			}
		}
	}
	delete[] queue;
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
	int start;

	do {	
		std::cout << "В графе " << n << " вершин. Введите номер вершины, с которой начнётся обход: ";
		std::cin >> start;
	} while (start > n || start <= 0);

	std::cout << "Порядок обхода вершин: ";

	bool* visited = new bool[n]();

	bfs(start, graph, visited, n);

	std::cout << std::endl;

	for (int i = 0; i < n; ++i) {
		delete[] graph[i];
	}
	delete[] graph;
	delete[] visited;
	return 0;
}
