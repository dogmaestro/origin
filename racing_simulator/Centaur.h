#pragma once
#include <string>
#include "LandVehicle.h"

class Centaur : public LandVehicle {
public:
	std::string getName() const;
	double getRaceTime(double distance) const;
};