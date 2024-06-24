#include "Broom.h"

std::string Broom::getName() const {
	return "Метла";
};

double Broom::getRaceTime(double distance) const {
	return calcRaceTimeByPrpgressiveFactor(20, 1, distance);
}
