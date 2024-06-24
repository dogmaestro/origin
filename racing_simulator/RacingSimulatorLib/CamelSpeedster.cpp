#include "CamelSpeedster.h"

std::string CamelSpeedster::getName() const {
	return "Верблюд-быстроход";
};

double CamelSpeedster::getRaceTime(double distance) const {
	const int restDurationsCount = 3;
	double restDurations[restDurationsCount] = { 5, 6.5, 8 };

	return calcRaceTime(40, 10, restDurations, restDurationsCount, distance);
}
