#pragma once
#include <string>
#include "AirVehicle.h"

class Eagle : public AirVehicle {
public:
	std::string getName() const;
	double getRaceTime(double distance) const;
};