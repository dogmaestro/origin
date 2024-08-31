#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <numeric>
#include "Utils.h"
#include "LineIterator.h"
#include "ini_parser.h"

std::string ini_parser::getRawValue(const std::string& sectionWithKey) {
	std::pair<std::string, std::string> sectionValuePair = getSectionValuePair(sectionWithKey);
	if (sectionValuePair.first == "" || sectionValuePair.second == "") {
		throw std::runtime_error("Имя перемнной задано некорректно.");
	}

	std::unordered_map<std::string, std::string> section;
	std::string value;

	try {
		section = parsed_data_.at(sectionValuePair.first);
	}
	catch (const std::out_of_range& e) {
		throw std::runtime_error("Секция не найдена: " + sectionValuePair.first);
	}

	try {
		value = section.at(sectionValuePair.second);
		return value;
	}
	catch (const std::out_of_range& e) {
		std::string message{ "Переменная " + sectionValuePair.second + " не найдена для секции " + sectionValuePair.first + ". " };
		std::string availableKeys = std::accumulate(
			section.begin(), section.end(), std::string(),
			[](const std::string& accStr, const std::pair<const std::string, std::string>& pair) {
				return accStr + pair.second;
			}
		);
		if (availableKeys != "") {
			message = message + "Доступные переменные:" + availableKeys;
		}
		throw std::runtime_error(message);
	}
}

ini_parser::ini_parser(const std::string& filename) : filename_(filename) {
	std::ifstream file{ filename_ };
	std::string section{ "" };
	size_t nline{ 0 };
	auto process_line = [&](const std::string& line) {
		nline++;
		if (isEmptyLine(line) || isComment(line)) {
		}
		else if (isSection(line)) {
			section = getSectionName(line);
			addSection(section);
		}
		else if (isVariable(line)) {
			if (section == "") {
				throw std::runtime_error("Заголовок секции отсутствует");
			}
			std::pair<std::string, std::string> variable = getVariablePair(line);
			addVariable(section, variable.first, variable.second);
		}
		else {
			throw std::runtime_error("Неверный формат строки");
		}
	};

	try {
		if (file.is_open()) {
			std::for_each(LineIterator(file), LineIterator(), process_line);
			file.close();
		}
		else {
			throw std::runtime_error("Ошибка открытия файла:  " + filename_);
		}
	}
	catch (const std::exception& e) {
		throw std::runtime_error(std::string(e.what()) + ". Строка " + std::to_string(nline));
	}
}

void ini_parser::addSection(const std::string& sectionName) {
	auto v = parsed_data_[sectionName];
}

void ini_parser::addVariable(const std::string& sectionName, const std::string& variableName, const std::string& variableValue) {
	parsed_data_[sectionName][variableName] = variableValue;
}
