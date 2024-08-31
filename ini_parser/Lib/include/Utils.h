#pragma once

#include <string>

//std::string LeftTrim(const std::string& str);

//std::string RightTrim(const std::string& str);

std::string trim(const std::string&);

bool isSection(const std::string&);

std::string getSectionName(const std::string&);

bool isVariable(const std::string&);

std::string removeComment(const std::string&);

std::pair<std::string, std::string> getPairFromString(const std::string&, const std::string&);

std::pair<std::string, std::string> getVariablePair(const std::string&);

std::pair<std::string, std::string> getSectionValuePair(const std::string&);

bool isComment(const std::string& str);

bool isEmptyLine(const std::string& str);
