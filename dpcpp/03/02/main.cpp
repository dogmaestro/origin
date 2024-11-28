#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>

class Observer {
public:
  virtual void onWarning(const std::string &message) {}
  virtual void onError(const std::string &message) {}
  virtual void onFatalError(const std::string &message) {}
};

class ConsoleWarningObserver : public Observer {
public:
  void onWarning(const std::string &message) override {
    std::cout << message << std::endl;
  }
};

class FileErrorObserver : public Observer {
public:
  FileErrorObserver(const std::string &filePath) : filePath_(filePath) {}

  void onError(const std::string &message) override {
    std::ofstream file(filePath_, std::ios_base::app);
    if (file.is_open()) {
      file << message << std::endl;
      file.close();
    } else {
      std::cerr << "Ошибка открытия файла: " << filePath_ << std::endl;
    }
  }

private:
  std::string filePath_;
};

class ConsoleAndFileFatalObserver : public Observer {
public:
  ConsoleAndFileFatalObserver(const std::string &filePath)
      : filePath_(filePath) {}

  void onFatalError(const std::string &message) override {
    std::cout << message << std::endl;
    std::ofstream file(filePath_, std::ios_base::app);
    if (file.is_open()) {
      file << message << std::endl;
      file.close();
    } else {
      std::cerr << "Ошибка открытия файла: " << filePath_ << std::endl;
    }
  }

private:
  std::string filePath_;
};

class Observable {
public:
  void addObserver(Observer *obs) { observers.push_back(obs); }

  void removeObserver(Observer *obs) {
    std::vector<Observer*>::iterator it = std::remove(observers.begin(), observers.end(), obs);
    observers.erase(it, observers.end());
  }

  void warning(const std::string &message) const {
    for (Observer *obs : observers) {
      obs->onWarning(message);
    }
  }

  void error(const std::string &message) const {
    for (Observer *obs : observers) {
      obs->onError(message);
    }
  }

  void fatalError(const std::string &message) const {
    for (Observer *obs : observers) {
      obs->onFatalError(message);
    }
  }

private:
  std::vector<Observer*> observers;
};

int main() {
  Observable observable;
  ConsoleWarningObserver consoleWarningObserver;
  FileErrorObserver fileErrorObserver("errors.txt");
  ConsoleAndFileFatalObserver consoleAndFileFatalObserver("fatal_errors.txt");

  observable.addObserver(&consoleWarningObserver);
  observable.addObserver(&fileErrorObserver);
  observable.addObserver(&consoleAndFileFatalObserver);

  observable.warning("Предупреждение...");
  observable.error("Ошибка...");
  observable.fatalError("Фатальная ошибка...");

  observable.removeObserver(&consoleWarningObserver);
  observable.removeObserver(&fileErrorObserver);
  observable.removeObserver(&consoleAndFileFatalObserver);

  return 0;
}
