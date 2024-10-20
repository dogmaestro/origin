#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <map>
#include <mutex>
#include <thread>
#include <vector>

std::once_flag flag;
std::vector<int> sizes = {1000, 10000, 100000, 1000000};
std::vector<int> threadCounts = {1, 2, 4, 8, 16};

void moveCursorToLine(int line) { std::cout << "\033[" << line << ";0H"; }

void print_header() {
  std::cout << "\033[2J";
  moveCursorToLine(1);

  int numCores = std::thread::hardware_concurrency();

  std::cout << "Количество аппаратных ядер: " << numCores << std::endl
            << std::endl;

  std::cout << std::setw(20) << "                        ";

  for (int size : sizes) {
    std::cout << size << std::setw(20);
  }

  std::cout << std::endl;
}

void sumVectors(const std::vector<int> &a, const std::vector<int> &b,
                std::vector<int> &result, int start, int end) {

  std::call_once(flag, print_header);

  for (int i = start; i < end; ++i) {
    result[i] = a[i] + b[i];
  }
}

double calcSum(int numThreads, const std::vector<int> &a,
               const std::vector<int> &b, std::vector<int> &result) {
  int size = a.size();
  std::vector<std::thread> threads;
  int chunkSize = size / numThreads;

  auto start_time = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < numThreads; ++i) {
    int start = i * chunkSize;
    int end = (i == numThreads - 1) ? size : start + chunkSize;
    threads.emplace_back(sumVectors, std::cref(a), std::cref(b),
                         std::ref(result), start, end);
  }

  for (auto &t : threads) {
    t.join();
  }

  auto end_time = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end_time - start_time;
  return elapsed.count();
}

int main() {

  std::cout << std::fixed << std::setprecision(7);

  int line = 4;
  std::map<int, std::vector<double>> result;

  for (int numThreads : threadCounts) {
    std::vector<double> row{};

    for (int size : sizes) {
      std::vector<int> a(size, 1);
      std::vector<int> b(size, 2);
      std::vector<int> result(size);

      double execTime = calcSum(numThreads, a, b, result);

      row.push_back(execTime);
    }
    result[numThreads] = row;
  }
  std::cout << std::setw(0) << std::endl;

  for (int numThreads : threadCounts) {
    std::cout << std::setw(20) << (std::to_string(numThreads) + " потоков ");
    std::vector<double> row = result[numThreads];
    for (double value : row) {
      std::cout << std::setw(20) << value;
    }
    std::cout << std::endl;
  }

  return 0;
}
