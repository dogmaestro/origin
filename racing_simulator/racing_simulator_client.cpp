#include <iostream>
#include <algorithm>
#include "Vehicle.h"
#include "VehicleFactory.h"
#define MAX_VEHICLES 50

class Game {
private:
	int raceType{};
	int numberOfRegisteredVehicles{};
	double distance{};
	size_t totalVehicles;
	Vehicle** availableVehicles; 
	Vehicle* participatingVehicles[MAX_VEHICLES] = {};
	bool registered{ false };
	bool completed{ false };
	std::string raceNames[3] = { "Гонка для наземного транспорта", "Гонка для воздушного транспорта", "Гонка для наземного и воздушного транспорта" };
	struct PlayerResult {
		std::string name{};
		double raceTime{};
	};
	PlayerResult results[MAX_VEHICLES] = {};

	void getRaceType();
	void getDistance();
	int registerVehicleAndGetType();
	int getActionForRegisterOrRun();
	int getActionForAnotherRace();
	void printGameData();
	int getVehicleType();
	bool checkVehicleType(int);
	void Run();

public:
	Game();
	~Game();
	void Play();
};

Game::Game() {
	availableVehicles = makeVehicles(totalVehicles);
}

Game::~Game() {
	for (int i = 0; i < totalVehicles; i++) {
		delete availableVehicles[i];
	}
	delete[] availableVehicles;
}

void Game::Play() {
	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
	do {
		registered = false;
		completed = false;
		numberOfRegisteredVehicles = 0;
		getRaceType();
		getDistance();

		do {
			if (getActionForRegisterOrRun() == 1) {
				do {
					printGameData();
					if (registerVehicleAndGetType() == 0) {
						if (numberOfRegisteredVehicles >= 2) {
							registered = true;
						}
						else {
							registered = false;
						}
						break;
					}
				} while (true);
			}
			else {
				if (registered) {
					Run();
				}
			}
		} while (!completed);
	} while (getActionForAnotherRace() != 2);
}

void Game::getRaceType() {
	do {
		for (int i = 0; i < 3; i++) {
			std::cout << i + 1 << ". " << raceNames[i] << std::endl;
		}
		std::cout << "Выберите тип гонки: ";
		std::cin >> raceType;
	} while (raceType != 1 && raceType != 2 && raceType != 3);
}

void Game::getDistance() {
	do {
		std::cout << "Укажите длину дистанции (должна быть положительна): ";
		std::cin >> distance;
	} while (distance <= 0);
}

int Game::getActionForRegisterOrRun() {
	int action;
	do {
		if (!registered) {
			std::cout << "\nДолжно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
		}
		std::cout << "1. Зарегистрировать транспорт" << std::endl;
		if (registered) {
			std::cout << "2. Начать гонку" << std::endl;
		}
		std::cout << "Выберите действие: ";
		std::cin >> action;
		if (registered) {
			if (action == 1 || action == 2) {
				break;
			}
		}
		else {
			if (action == 1) {
				break;
			}
		}

	} while (true);
	return action;
}

int Game::getActionForAnotherRace() {
	int actionAfterRace = 0;
	do {
		std::cout << "1. Провести еще одну гонку" << std::endl;
		std::cout << "2. Выйти" << std::endl;
		std::cout << "Выберите действие: ";
		std::cin >> actionAfterRace;
	} while (actionAfterRace != 1 && actionAfterRace != 2);
	return actionAfterRace;
}

void Game::printGameData() {
	std::cout << raceNames[raceType - 1] << ". Расстояние: " << distance << std::endl;
	if (numberOfRegisteredVehicles > 0) {
		std::cout << "Зарегистрированные транспортные средства: ";
		for (int i = 0; i < numberOfRegisteredVehicles; i++) {
			std::cout << participatingVehicles[i]->getName() << (i == (numberOfRegisteredVehicles - 1) ? " " : ", ");
		}
		std::cout << std::endl;
	}
}

int Game::getVehicleType() {
	int vehicleType;
	for (int i = 0; i < totalVehicles; i++) {
		std::cout << i + 1 << ". " << availableVehicles[i]->getName() << std::endl;
	}
	std::cout << "0. Закончить регистрацию" << std::endl;
	do {
		std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
		std::cin >> vehicleType;
	} while (vehicleType < 0 || vehicleType > totalVehicles);
	return vehicleType;
}

bool Game::checkVehicleType(int registeringVehicleType) {
	int checkParticipaiting = false;
	if (numberOfRegisteredVehicles > 0) {
		for (int i = 0; i < numberOfRegisteredVehicles; i++) {
			if (availableVehicles[registeringVehicleType - 1]->getName() == participatingVehicles[i]->getName()) {
				checkParticipaiting = true;
				break;
			}
		}
	}
	if (checkParticipaiting) {
		std::cout << availableVehicles[registeringVehicleType - 1]->getName() << " уже зарегистрирован!" << std::endl;
		return false;
	}
	if (raceType == 1 || raceType == 2) {
		if (availableVehicles[registeringVehicleType - 1]->getMode() != static_cast<VehicleMode>(raceType)) {
			std::cout << "Попытка зарегистрировать неправильный тип транспортного средства! " << std::endl;
			return false;
		}
	}
	return true;
}

int Game::registerVehicleAndGetType() {
	int registeringVehicleType = 0;
	do {
		registeringVehicleType = getVehicleType();
		if (registeringVehicleType == 0) {
			break;
		}
		if (!checkVehicleType(registeringVehicleType)) {
			continue;
		}
		participatingVehicles[++numberOfRegisteredVehicles - 1] = availableVehicles[registeringVehicleType - 1];
		std::cout << availableVehicles[registeringVehicleType - 1]->getName() << " успешно зрегистрирован!" << std::endl;
	} while (registeringVehicleType < 0 || registeringVehicleType > totalVehicles);
	return registeringVehicleType;
}

void Game::Run() {
	PlayerResult results[MAX_VEHICLES] = {};
	std::cout << "Результаты гонки:" << std::endl;
	for (int i = 0; i < numberOfRegisteredVehicles; i++) {
		PlayerResult playerResult{ participatingVehicles[i]->getName() , participatingVehicles[i]->getRaceTime(distance) };
		results[i] = playerResult;
	}
	std::sort(results, results + numberOfRegisteredVehicles,
		[](PlayerResult const& a, PlayerResult const& b) -> bool
		{ return a.raceTime < b.raceTime; });
	for (int i = 0; i < numberOfRegisteredVehicles; i++) {
		std::cout << i + 1 << ". " << results[i].name << ". Время: " << results[i].raceTime << std::endl;
	}
	completed = true;
	std::cout << std::endl;
}

int main() {
	Game game;
	game.Play();
	return 0;
}
