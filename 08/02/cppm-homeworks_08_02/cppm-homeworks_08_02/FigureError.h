#pragma once
#include <stdexcept>

class FigureError : public std::domain_error {
public:
    FigureError(const std::string& message);
};
