#include <algorithm>
#include <future>
#include <iostream>
#include <iterator>
#include <vector>

template <typename Iterator, typename Func>
void parallel_for_each(Iterator first, Iterator last, Func f,
                       int size_ = 1000) {
  int distance = std::distance(first, last);

  if (distance <= size_) {
    std::for_each(first, last, f);
    return;
  }
  Iterator middle = std::next(first, distance / 2);

  auto future_left =
      std::async(std::launch::async, parallel_for_each<Iterator, Func>, first,
                 middle, f, size_);
  auto future_right =
      std::async(std::launch::async, parallel_for_each<Iterator, Func>, middle,
                 last, f, size_);

  future_left.get();
  future_right.get();
}

int main() {
  int size = 10000;
  std::vector<int> vec(size, 1);

  for (int i = 1; i <= size; ++i) {
    vec[i - 1] = i;
  }

  parallel_for_each(vec.begin(), vec.end(),
                    [](int i) { std::cout << i << " "; });

  std::cout << std::endl;

  return 0;
}
