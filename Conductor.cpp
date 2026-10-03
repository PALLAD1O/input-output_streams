#include "Conductor.h"
#include <iostream>
using namespace std;
Conductor::Conductor() : Employee(), wagonNumber(0), shift("Дневная") {}
Conductor::Conductor(string Name, int Age, double Salary, int WagonNumber, string Shift) : Employee(Name, Age, Salary), wagonNumber(WagonNumber), shift(Shift) {}

int Conductor::getWagonNumber() const { return wagonNumber; }
string Conductor::getShift() const { return shift; }

void Conductor::setWagonNumber(int WagonNumber) { wagonNumber = WagonNumber; }
void Conductor::setShift(string Shift) { shift = Shift; }

string Conductor::getPosition() const { return "Проводник"; }
void Conductor::input() {
	Employee::input();
	cout << "Введите номер вагона, закреплённый за проводником: ";
	while (true) {
		cin >> wagonNumber;
		if (cin.fail()) {
			cout << "Некорректно введены данные, пожалуйста, повторите попытку: ";
			cin.ignore(1000, '\n');
			cin.clear();
			continue;
		}
		if (wagonNumber < 1) {
			cout << "Обычно номера начинаются с 1 и не уходят в минус, повторите попытку: ";
			continue;
		}
		break;
	}
	cout << "Введите смену проводника: ";
	if (cin.peek() == '\n') cin.ignore();
	getline(cin, shift);
}