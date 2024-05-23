#include "FigureError.h"
FigureError::FigureError(const std::string& message): std::domain_error("Ошибка создания фигуры. " + message) {}