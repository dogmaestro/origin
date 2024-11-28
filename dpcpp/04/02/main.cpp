#include <fstream>
#include <stdexcept>
#include <string>

class DataFormatter {
public:
  virtual ~DataFormatter() = default;
  virtual std::string format(const std::string &data) const = 0;
};

class HtmlFormatter : public DataFormatter {
public:
  std::string format(const std::string &data) const override {
    return "<html>" + data + "</html>";
  }
};

class TextFormatter : public DataFormatter {
public:
  std::string format(const std::string &data) const override { return data; }
};

class JsonFormatter : public DataFormatter {
public:
  std::string format(const std::string &data) const override {
    return "{ \"data\": \"" + data + "\"}";
  }
};

class TextDataSaver {
public:
  void save(const std::string &data, std::ofstream &file) const {
     file << data;
   };
};

class Data {
public:
  Data(std::string data) : data_(std::move(data)) {}
  const std::string &getData() const { return data_; }

private:
  std::string data_;
};

void saveData(const Data &data, std::ofstream &file,
              const DataFormatter &formatter, const TextDataSaver &saver) {
  saver.save(formatter.format(data.getData()), file);
}

int main() {
  Data myData("Tesd data");
  std::ofstream outputHTMLFile("output.html");

  saveData(myData, outputHTMLFile, HtmlFormatter(), TextDataSaver());
  outputHTMLFile.close();

  std::ofstream outputTXTFile("output.txt");
  saveData(myData, outputTXTFile, TextFormatter(), TextDataSaver());
  outputTXTFile.close();

  std::ofstream outputJSONFile("output.json");
  saveData(myData, outputJSONFile, JsonFormatter(), TextDataSaver());
  outputJSONFile.close();

  return 0;
}
