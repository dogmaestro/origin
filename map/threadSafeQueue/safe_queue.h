#pragma once
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

template <typename T> class safe_queue {
private:
  std::queue<T> q;
  std::mutex m;
  std::condition_variable cv;
  bool stop = false; 
public:
  void push(T &&data);
  bool pop(T&& result);
  bool empty();
  void setStop();
};

template <typename T> 
void safe_queue<T>::push(T &&data) {
  std::unique_lock<std::mutex> lock(m);
  q.emplace(std::move(data));
  lock.unlock();
  cv.notify_one();
}

template <typename T> 
bool safe_queue<T>::pop(T&& result) {
  std::unique_lock<std::mutex> lock(m);
  cv.wait(lock, [this] { return !q.empty()||stop; });
  if (stop && q.empty()) return false; 
  result = std::move(q.front());
  q.pop();
  return true;
}

template <typename T> 
bool safe_queue<T>::empty() {
  std::unique_lock<std::mutex> lock(m);
  return q.empty();
}

template <typename T> 
void safe_queue<T>::setStop() {
  std::unique_lock<std::mutex> lock(m);
  stop = true;
  cv.notify_all(); 
}

