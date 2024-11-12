#include "thread_pool.h"
#include <future>
#include <random>
#include <sched.h>
#include <thread>

int main() {
  size_t num_threads = std::thread::hardware_concurrency();
  thread_pool pool(num_threads);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(1, 20);

  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j < 2; ++j) {
      int n = distrib(gen);
      auto task = std::packaged_task<void()>([n]() {
        std::cout << "Задание " << n << std::endl;
      });
      pool.submit(std::move(task));
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  std::cout << "Все задания помещены в очередь." << std::endl;

  return 0;
}
