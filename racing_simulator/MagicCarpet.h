#pragma once
#include <string>
#include "AirVehicle.h"

class MagicCarpet : public AirVehicle {
public:
	std::string getName() const;
	double getRaceTime(double distance) const;
};