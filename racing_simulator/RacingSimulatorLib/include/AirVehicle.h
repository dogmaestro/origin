#pragma once
#include "Vehicle.h"

struct DistanceReductionPair {
	double distance;
	int distanceReductionFactor;
};

class AirVehicle : public Vehicle {
public:
	VehicleMode getMode() const override;
protected:
	double calcRaceTimeByDistanceReductionPairs(double velocity, DistanceReductionPair* distanceReductionPairs, int distanceReductionPairsCount, double distance) const;
	double calcRaceTimeByPrpgressiveFactor(double velocity, double factor, double distance) const;
};