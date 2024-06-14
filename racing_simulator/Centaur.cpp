#include "Centaur.h"

std::string Centaur::getName() const {
	return "Кентавр";
};

double Centaur::getRaceTime(double distance) const {
	const int restDurationsCount = 1;
	double restDurations[restDurationsCount] = { 2 };

	return calcRaceTime(15, 8, restDurations, restDurationsCount, distance);
}
