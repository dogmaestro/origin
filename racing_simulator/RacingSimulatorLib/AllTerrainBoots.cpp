#include "AllTerrainBoots.h"

std::string AllTerrainBoots::getName() const {
	return "Ботинки-вездеходы";
};

double AllTerrainBoots::getRaceTime(double distance) const {
	const int restDurationsCount = 2;
	double restDurations[restDurationsCount] = { 10, 5 };

	return calcRaceTime(6, 60, restDurations, restDurationsCount, distance);
}
