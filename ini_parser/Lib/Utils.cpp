#include "Utils.h"

std::string rtrim(const std::string& str) {
	size_t end = str.find_last_not_of(" \t\n\r\f\v");
	return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

std::string ltrim(const std::string& str) {
	size_t start = str.find_first_not_of(" \t\n\r\f\v");
	return (start == std::string::npos) ? "" : str.substr(start);
}

std::string trim(const std::string& str) {
	return rtrim(ltrim(str));
}

bool isSection(const std::string& str) {
	std::string trimmedStr = trim(str);
	if (trimmedStr[0] == '[' && trimmedStr[trimmedStr.size() - 1] == ']') {
		return true;
	}
	return false;
}

std::string getSectionName(const std::string& str) {
	std::string trimmedStr = trim(str);
	return trimmedStr.substr(1, trimmedStr.size() - 2);
}

bool isVariable(const std::string& str) {
	std::string trimmedStr = trim(str);
	size_t pos = trimmedStr.find_first_of("=");
	if (pos == std::string::npos) {
		return false;
	}
	std::string key = trim(trimmedStr.substr(0, pos));
	if (key == "") {
		return false;
	}
	return true;
}

std::string removeComment(const std::string& str) {
	size_t pos_comment{ std::string::npos };
	std::string trimmedStr = trim(str);
	if (trimmedStr[0] == '"') {
		size_t pos = trimmedStr.find_first_of('"', 1);
		if (pos != std::string::npos) {
			pos_comment = trimmedStr.find_first_of(';', pos);
		}
	}
	else {
		pos_comment = trimmedStr.find_first_of(';', 1);
	}
	return (pos_comment == std::string::npos) ? str : str.substr(0, pos_comment);
}

std::pair<std::string, std::string> getPairFromString(const std::string& str, const std::string& delimiter) {
	std::string key{ "" };
	std::string value{ "" };
	std::string trimmedStr = trim(str);
	size_t pos = trimmedStr.find_first_of(delimiter);
	if (pos == std::string::npos) {
		key = trimmedStr;
	}
	else {
		key = trim(trimmedStr.substr(0, pos));
		value = trim(removeComment(trimmedStr.substr(pos + 1)));
	}
	return std::pair<std::string, std::string>(key, value);
}

std::pair<std::string, std::string> getVariablePair(const std::string& str) {
	return getPairFromString(str, "=");
}

std::pair<std::string, std::string> getSectionValuePair(const std::string& str) {
	return getPairFromString(str, ".");
}

bool isComment(const std::string& str) {
	std::string trimmedStr = trim(str);
	if (trimmedStr[0] == ';') {
		return true;
	}
	return false;
}

bool isEmptyLine(const std::string& str) {
	std::string trimmedStr = trim(str);
	if (trimmedStr == "") {
		return true;
	}
	return false;
}
