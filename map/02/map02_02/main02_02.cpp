#include <chrono>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <thread>
#include <vector>

std::mutex console_mutex;

void moveCursorToLine(int line) { std::cout << "\033[" << line << ";0H"; }

void progressBar(int thread_num, int duration, int total_threads) {
  auto start_time = std::chrono::steady_clock::now();
  std::thread::id thread_id = std::this_thread::get_id();

  const int steps = 10;
  int sleep_time_per_step = duration / steps;
  bool hasError = false;

  try {
    for (int i = 0; i < steps; ++i) {
      if (thread_num == 3 && i == 5) {
        throw std::runtime_error("Ошибка  " + std::to_string(thread_num));
      }

      std::this_thread::sleep_for(
          std::chrono::milliseconds(sleep_time_per_step));

      {
        std::lock_guard<std::mutex> lock(console_mutex);

        moveCursorToLine(thread_num + 1);

        std::cout << thread_num << " " << thread_id << " ";

        for (int j = 0; j <= i; ++j) {
          std::cout << "█";
        }

        for (int j = i + 1; j < steps; ++j) {
          std::cout << " ";
        }

        std::cout << std::flush;
      }
    }
  } catch (const std::exception &e) {
    hasError = true;
    std::lock_guard<std::mutex> lock(console_mutex);
    moveCursorToLine(thread_num + 1);
    std::cout << "\033[31m" << thread_num << " " << thread_id << " "
              << e.what();
  }

  auto end_time = std::chrono::steady_clock::now();
  auto time_spent = std::chrono::duration_cast<std::chrono::milliseconds>(
                        end_time - start_time)
                        .count();

  {
    std::lock_guard<std::mutex> lock(console_mutex);
    moveCursorToLine(thread_num + 1);
    if (!hasError) {
      std::cout << thread_num << " " << thread_id << " ";

      for (int i = 0; i < steps; ++i) {
        std::cout << "█";
      }

      std::cout << "                   " << time_spent / 1000. << "s"
                << std::flush;
    }
  }
}

int main() {
  int num_threads = 5;

  std::vector<double> durations = {2621, 1500, 8000, 3500, 3000};

  std::vector<std::thread> threads;

  std::cout << "\033[2J";

  moveCursorToLine(1);

  std::cout << "#  id              progress bar                time";

  for (int i = 0; i < num_threads; ++i) {
    threads.emplace_back(progressBar, i + 1, durations[i], num_threads);
  }

  for (auto &thread : threads) {
    thread.join();
  }

  moveCursorToLine(num_threads + 3);

  return 0;
}
