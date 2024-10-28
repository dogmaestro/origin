#include <algorithm>
#include <future>
#include <iostream>
#include <vector>

void find_min(const std::vector<int> &arr, int start, int end,
              std::promise<int> &promise) {
  int min_idx = start;
  for (int i = start + 1; i <= end; ++i) {
    if (arr[i] < arr[min_idx]) {
      min_idx = i;
    }
  }
  promise.set_value(min_idx);
};

int find_min_index_async(const std::vector<int> &arr, int start, int end) {
  std::promise<int> promise;
  std::future<int> future = promise.get_future();

  auto f = std::async(std::launch::async, find_min, std::ref(arr), start, end,
                      std::ref(promise));
  return future.get();
}

void selection_sort(std::vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    int min_idx = find_min_index_async(arr, i, n - 1);
    if (min_idx != i) {
      std::swap(arr[i], arr[min_idx]);
    }
  }
}

int main() {
  std::vector<int> arr = {99, 88, 77, 66, 55};

  std::cout << "Неупорядоченный массив: ";
  for (int val : arr) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  selection_sort(arr);

  std::cout << "Упорядоченный массив: ";
  for (int val : arr) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  return 0;
}
