#include <iostream>
#include <fstream>

void dfs(int vertex, int** graph, int n, int* cids, int cid) {
	cids[vertex] = cid;
	for (int i = 0; i < n; ++i) {
		if (graph[vertex][i]) {
			if (cids[i] == 0) {
				dfs(i, graph, n, cids, cid);
			}
		}
	}
}

void components(int** graph, int n, int* cids, int& cid) {
	for (int i = 0; i < n; ++i) {
		if (cids[i] == 0) {
			dfs(i, graph, n, cids, cid);
			cid++;
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

	int* cids = new int[n]();
	int cid = 1;

	components(graph, n, cids, cid);

	std::cout << "Принадлежность вершин компонентам связности:" << std::endl;
	for (int i = 0; i < n; ++i) {
		std::cout << i + 1 << " - " << cids[i] << std::endl;
	}
	std::cout << "Количество компонентов связности в графе: " << cid - 1 << std::endl;

	for (int i = 0; i < n; ++i) {
		delete[] graph[i];
	}
	delete[] graph;
	delete[] cids;

	return 0;
}
