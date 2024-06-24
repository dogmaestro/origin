#include "Eagle.h"

std::string Eagle::getName() const {
	return "Орел";
};

double Eagle::getRaceTime(double distance) const {
	const int distanceReductionPairsCount = 1;
	DistanceReductionPair distanceReductionPairs[distanceReductionPairsCount] = { { std::numeric_limits<double>::max(), 6 } };

	return calcRaceTimeByDistanceReductionPairs(8, distanceReductionPairs, distanceReductionPairsCount, distance);
}
