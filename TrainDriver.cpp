#include "TrainDriver.h"
#include <iostream>
using namespace std;
TrainDriver::TrainDriver() : Employee(), trainType("Пассажирский"), rollingHours(0) {}
TrainDriver::TrainDriver(string Name, int Age, double Salary, string TrainType, int RollingHours) : Employee(Name, Age, Salary), trainType(TrainType), rollingHours(RollingHours) {}

string TrainDriver::getTrainType() const { return trainType; }
int TrainDriver::getRollingHours() const { return rollingHours; }

void TrainDriver::setTrainType(string TrainType) { trainType = TrainType; }
void TrainDriver::setRollingHours(int RollingHours) { rollingHours = RollingHours; }

string TrainDriver::getPosition() const { return "Машинист"; }
void TrainDriver::input() {
	Employee::input();
	cout << "Введите тип поезда, которым управляет машинист: ";
	if (cin.peek() == '\n') cin.ignore();
	getline(cin, trainType);
	cout << "Введите количество накатанных часов на этих поездах: ";
	while (true) {
		cin >> rollingHours;
		if (cin.fail()) {
			cout << "Некорректно введены данные, пожалуйста, повторите попытку: ";
			cin.ignore(1000, '\n');
			cin.clear();
			continue;
		}
		if (rollingHours < 0) {
			cout << "К сожалению, этот минус в графе \"время\" вас моложе не сделает, повторите попытку: ";
			continue;
		}
		break;
	}
}