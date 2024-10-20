#include <cassert>
#include <iostream>
#include <mutex>

class Data {
public:
  int value;
  std::mutex mtx;

  Data(int v) : value(v) {}
};

void swap_using_lock(Data &l, Data &r) {
  std::lock(l.mtx, r.mtx);

  std::swap(l.value, r.value);

  l.mtx.unlock();
  r.mtx.unlock();
}

void swap_using_scoped_lock(Data &l, Data &r) {
  std::scoped_lock lock(l.mtx, r.mtx);

  std::swap(l.value, r.value);
}

void swap_using_unique_lock(Data &l, Data &r) {
  std::unique_lock<std::mutex> lock_l(l.mtx, std::defer_lock);
  std::unique_lock<std::mutex> lock_r(r.mtx, std::defer_lock);

  std::lock(lock_l, lock_r);

  std::swap(l.value, r.value);
}

int main() {
  {
    Data a(10), b(20);
    swap_using_lock(a, b);
    assert(a.value == 20);
    assert(b.value == 10);
  }

  {
    Data a(10), b(20);
    swap_using_scoped_lock(a, b);
    assert(a.value == 20);
    assert(b.value == 10);
  }

  {
    Data a(10), b(20);
    swap_using_unique_lock(a, b);
    assert(a.value == 20);
    assert(b.value == 10);
  }

  return 0;
}
