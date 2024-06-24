#include "Camel.h"

std::string Camel::getName() const {
	return "Верблюд";
};

double Camel::getRaceTime(double distance) const {
	const int restDurationsCount = 2;
	double restDurations[restDurationsCount] = { 5, 8 };

	return calcRaceTime(10, 30, restDurations, restDurationsCount, distance);
}