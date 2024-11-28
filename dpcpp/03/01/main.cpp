#include <fstream>
#include <iostream>

class LogCommand {
public:
  virtual ~LogCommand() = default;
  virtual void print(const std::string &message) = 0;
};

class ConsoleLogCommand : public LogCommand {
public:
  void print(const std::string &message) override {
    std::cout << message << std::endl;
  }
};

class FileLogCommand : public LogCommand {
public:
  FileLogCommand(const std::string &filePath) : filePath_(filePath) {}

  void print(const std::string &message) override {
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

void print(LogCommand &command, const std::string &message) {
  command.print(message);
}

int main() {
  ConsoleLogCommand consoleCommand;
  FileLogCommand fileCommand("log.txt");

  print(consoleCommand, "Сообщение в консоль.");
  print(fileCommand, "Сообщение в файл.");

  return 0;
}
