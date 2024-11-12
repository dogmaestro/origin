#pragma once
#include "safe_queue.h"
#include <functional>
#include <future>
#include <vector>


class thread_pool {
private:
  safe_queue<std::packaged_task<void()>> task_queue;
  std::vector<std::thread> threads;
  std::promise<void> stopPromise;
  std::future<void> stopFuture;
public:
  thread_pool(size_t num_threads);

  ~thread_pool();

  void submit(std::packaged_task<void()> &&task);
};
