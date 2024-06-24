#pragma once
#include <string>
#include "LandVehicle.h"

class Camel : public LandVehicle {
public:
	std::string getName() const;
	double getRaceTime(double distance) const;
};