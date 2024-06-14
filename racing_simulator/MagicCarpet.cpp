#include "MagicCarpet.h"

std::string MagicCarpet::getName() const {
	return "Ковер-самолет";
};

double MagicCarpet::getRaceTime(double distance) const {
	const int distanceReductionPairsCount = 4;
	DistanceReductionPair distanceReductionPairs[distanceReductionPairsCount] = { { 1000, 0 }, { 5000, 3 }, { 10000, 10 }, { std::numeric_limits<double>::max(), 5 } };

	return calcRaceTimeByDistanceReductionPairs(10, distanceReductionPairs, distanceReductionPairsCount, distance);
}


