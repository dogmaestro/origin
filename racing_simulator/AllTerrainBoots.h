#pragma once
#include <string>
#include "LandVehicle.h"

class AllTerrainBoots : public LandVehicle {
public:
	std::string getName() const;
	double getRaceTime(double distance) const;
};