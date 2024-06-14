#include <cmath>
#include "LandVehicle.h"

VehicleMode LandVehicle::getMode() const {
	return VehicleMode::LAND;
};

double LandVehicle::calcRaceTime(double velocity, double timeBeforeRest, double* restDurations, int restDurationsCount, double distance) const {
	double timeForDistance = distance / velocity;
	int numTimesToRest = std::floor(timeForDistance / timeBeforeRest);
	if (timeForDistance / timeBeforeRest - numTimesToRest == 0) {
		numTimesToRest--;
	}
	double timeForRest = 0;

	if (restDurationsCount > 1 && numTimesToRest > 0) {
		for (int i = 0; i < restDurationsCount - 1; i++) {
			timeForRest += restDurations[i];
			numTimesToRest--;
			if (numTimesToRest == 0) {
				break;
			}			
		}
	}
	
	if (numTimesToRest > 0) {
		timeForRest += restDurations[restDurationsCount - 1] * numTimesToRest;
	}
	return timeForDistance + timeForRest;
}