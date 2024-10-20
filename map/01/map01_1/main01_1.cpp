#include <chrono>
#include <iostream>
#include <thread>

int clientCounter = 0;

void client(int maxClients) {
  int processed{0};
  while (true) {
    if (processed == maxClients) {
      return;
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));

    ++clientCounter;
    ++processed;
    std::cout << "Клиент стал в очередь, длина очереди: " << clientCounter
              << std::endl;
  }
}

void clerk(int maxClients) {
  int processed{0};
  while (true) {
    if (processed == maxClients) {
      return;
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));

    if (clientCounter > 0) {
      --clientCounter;
      ++processed;
      std::cout << "Клиент покинул очередь, длина очереди: " << clientCounter
                << std::endl;
    }
  }
}

int main() {
  int maxClients = 10;

  std::thread thread1(client, maxClients);
  std::thread thread2(clerk, maxClients);

  thread1.join();
  thread2.join();

  return 0;
}
