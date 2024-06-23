#pragma once
#include "Vehicle.h"
#include "Camel.h"
#include "CamelSpeedster.h"
#include "Centaur.h"
#include "AllTerrainBoots.h"
#include "MagicCarpet.h"
#include "Eagle.h"
#include "Broom.h"

Vehicle** makeVehicles(size_t& totalVehicles) {
	totalVehicles = 7;
	Vehicle** availableVehicles = new Vehicle* [totalVehicles];
	availableVehicles[0] = new AllTerrainBoots();
	availableVehicles[1] = new Broom();
	availableVehicles[2] = new Camel();
	availableVehicles[3] = new Centaur();
	availableVehicles[4] = new Eagle();
	availableVehicles[5] = new CamelSpeedster();
	availableVehicles[6] = new MagicCarpet();
	return availableVehicles;
}