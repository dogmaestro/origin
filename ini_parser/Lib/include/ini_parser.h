#pragma once
#include <string>
#include <unordered_map>

class ini_parser {
public:
	ini_parser(const std::string& filename);

	template<typename T>
	T get_value(const std::string& sectionWithKey) {
		std::string value_str = getRawValue(sectionWithKey);
		return convert_value<T>(value_str);
	}

private:

	std::string filename_;

	std::unordered_map<std::string, std::unordered_map<std::string, std::string> > parsed_data_;

	std::string getRawValue(const std::string& sectionWithKey);

	template<typename T>
	T convert_value(const std::string& value_str) const {
		throw std::runtime_error("Конвертация для данного типа не реализована");
	}

	void addSection(const std::string& sectionName);

	void addVariable(const std::string& sectionName, const std::string& variableName, const std::string& variableValue);
};

template<>
inline int ini_parser::convert_value<int>(const std::string& value_str) const {
	return std::stoi(value_str);
}

template<>
inline double ini_parser::convert_value<double>(const std::string& value_str) const {
	return std::stod(value_str);
}

template<>
inline std::string ini_parser::convert_value<std::string>(const std::string& value_str) const {
	return value_str;
}