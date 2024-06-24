#pragma once
#include <string>

enum class VehicleMode { LAND = 1, AIR };

class Vehicle {
public:
	virtual std::string getName() const = 0;
	virtual VehicleMode getMode() const = 0;
	virtual double getRaceTime(double distance) const = 0;
};