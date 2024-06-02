#pragma once
#include <string>

#ifdef CPPM_HOMEWORKS_11_04_EXPORTS
#define CPPM_HOMEWORKS_11_04_API __declspec(dllexport)
#else
#define CPPM_HOMEWORKS_11_04_API __declspec(dllimport)
#endif


class Figure {
public:
	CPPM_HOMEWORKS_11_04_API Figure();
	CPPM_HOMEWORKS_11_04_API virtual void print_info() = 0;
protected:
	std::string name;
	std::string get_name();
};