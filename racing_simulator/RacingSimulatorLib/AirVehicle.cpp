#include <cmath>
#include "AirVehicle.h"

VehicleMode AirVehicle::getMode() const {
	return VehicleMode::AIR;
};

double AirVehicle::calcRaceTimeByDistanceReductionPairs(double velocity, DistanceReductionPair* distanceReductionPairs, int distanceReductionPairsCount, double distance) const {
	double timeForDistance = distance / velocity;
	double factor = 0;
	for (int i = 0; i < distanceReductionPairsCount; i++) {
		if (distance < distanceReductionPairs[i].distance) {
			factor = distanceReductionPairs[i].distanceReductionFactor;
			break;
		}
	}
	timeForDistance -= (timeForDistance * factor) / 100;

	return timeForDistance;
}

double AirVehicle::calcRaceTimeByPrpgressiveFactor(double velocity, double progressiveFactor, double distance) const {
	double timeForDistance = distance / velocity;
	timeForDistance -= (timeForDistance * std::floor(distance / 1000) * progressiveFactor) / 100;

	return timeForDistance;
}
