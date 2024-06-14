#pragma once
#include <string>
#include "Vehicle.h"

class LandVehicle : public Vehicle {
public:
	VehicleMode getMode() const override;
protected:
	double calcRaceTime(double velocity, double timeBeforeRest, double* restDurations, int restDurationsCount, double distance) const;
};