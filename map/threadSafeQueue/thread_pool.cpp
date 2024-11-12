#include "thread_pool.h"
#include <exception>
#include <functional>
#include <future>
#include <thread>
#include <vector>

thread_pool::thread_pool(size_t num_threads)
    : stopFuture(stopPromise.get_future()) {
  try {
    for (size_t i = 0; i < num_threads; ++i) {
      threads.emplace_back([this] {
        while (stopFuture.wait_for(
                std::chrono::milliseconds(100)) == 
                std::future_status::timeout) {
          std::packaged_task<void()> task;
          if (task_queue.pop(std::move(task))) {
            if (!task.valid()) {
              break;
            }
            task();
          } else {
            std::this_thread::yield();
          }
        }
      });
    }
  } catch (...) {
    task_queue.setStop();
    stopPromise.set_value();
    for (auto &thread : threads) {
      if (thread.joinable()) {
        thread.join();
      }
    }
    threads.clear();
    throw;
  }
}

thread_pool::~thread_pool() {
  task_queue.setStop();
  stopPromise.set_value();

  for (auto &thread : threads) {
    if (thread.joinable()) {
      thread.join();
    }
  }
  threads.clear();
}

void thread_pool::submit(std::packaged_task<void()> &&task) {
  task_queue.push(std::move(task));
}
