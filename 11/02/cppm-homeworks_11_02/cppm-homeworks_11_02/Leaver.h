#pragma once

#include <string>

#ifdef CPPM_HOMEWORKS_11_02_EXPORTS
#define CPPM_HOMEWORKS_11_02_API __declspec(dllexport)
#else
#define CPPM_HOMEWORKS_11_02_API __declspec(dllimport)
#endif

class Leaver {
public:
	CPPM_HOMEWORKS_11_02_API std::string leave(std::string);
};
