#pragma once
#include <string>
#include "Camel.h"

class CamelSpeedster : public Camel {
public:
	std::string getName() const;
	double getRaceTime(double distance) const;
};