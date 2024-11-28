#include <exception>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

enum class LogMessageType { WARNING, ERROR, FATAL_ERROR, UNKNOWN };

class LogMessage {
public:
  LogMessage(LogMessageType type, const std::string &message)
      : type_(type), message_(message) {}
  LogMessageType type() const { return type_; }
  const std::string &message() const { return message_; }

private:
  LogMessageType type_;
  std::string message_;
};

class BaseLogHandler {
public:
  virtual void handle(const LogMessage &message) = 0;
  void setNextHandler(std::shared_ptr<BaseLogHandler> next) {
    nextHandler_ = std::move(next);
  }

protected:
  std::shared_ptr<BaseLogHandler> nextHandler_;
};

class WarningHandler : public BaseLogHandler {
public:
  void handle(const LogMessage &message) override {
    if (message.type() == LogMessageType::WARNING) {
      std::cout << "Предупреждение: " << message.message() << std::endl;
    } else if (nextHandler_) {
      nextHandler_->handle(message);
    } else {
      std::cout << "Обработчик не найден." << std::endl;
    }
  }
};

class ErrorHandler : public BaseLogHandler {
public:
  ErrorHandler(const std::string &filePath) : filePath_(filePath) {}
  void handle(const LogMessage &message) override {
    if (message.type() == LogMessageType::ERROR) {
      std::ofstream file(filePath_, std::ios_base::app);
      if (file.is_open()) {
        file << "Ошибка: " << message.message() << std::endl;
        file.close();
      } else {
        std::cerr << "Ошибка открытия файла: " << filePath_ << std::endl;
      }
    } else if (nextHandler_) {
      nextHandler_->handle(message);
    } else {
      std::cout << "Обработчик не найден." << std::endl;
    }
  }

private:
  std::string filePath_;
};

class FatalErrorHandler : public BaseLogHandler {
public:
  void handle(const LogMessage &message) override {
    if (message.type() == LogMessageType::FATAL_ERROR) {
      throw std::runtime_error("Фатальная ошибка: " + message.message());
    } else if (nextHandler_) {
      nextHandler_->handle(message);
    } else {
      std::cout << "Обработчик не найден." << std::endl;
    }
  }
};

class UnknownHandler : public BaseLogHandler {
public:
  void handle(const LogMessage &message) override {
    if (message.type() == LogMessageType::UNKNOWN) {
      throw std::runtime_error("Неизвестный тип сообщения: " +
                               message.message());
    } else if (nextHandler_) {
      nextHandler_->handle(message);
    }
  }
};

int main() {
  auto unknownHandler = std::make_shared<UnknownHandler>();
  auto warningHandler = std::make_shared<WarningHandler>();
  auto errorHandler = std::make_shared<ErrorHandler>("errors.log");
  auto fatalErrorHandler = std::make_shared<FatalErrorHandler>();

  fatalErrorHandler->setNextHandler(errorHandler);
  errorHandler->setNextHandler(warningHandler);
  warningHandler->setNextHandler(unknownHandler);

  try {
    fatalErrorHandler->handle(
        LogMessage{LogMessageType::WARNING, "warning message"});
    fatalErrorHandler->handle(LogMessage{LogMessageType::ERROR, "error message"});
    fatalErrorHandler->handle(
        LogMessage{LogMessageType::FATAL_ERROR, "fatal error message"});
    fatalErrorHandler->handle(
        LogMessage{LogMessageType::UNKNOWN, "unknown message"});
  } catch (const std::runtime_error &error) {
    std::cerr << error.what() << std::endl;
  }

  return 0;
}
