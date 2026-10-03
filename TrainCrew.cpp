#include "TrainCrew.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
TrainCrew::TrainCrew() : crewName(""), trainNumber(0), route("") {}
TrainCrew::TrainCrew(string CrewName, int TrainNumber, string Route) : crewName(CrewName), trainNumber(TrainNumber), route(Route) {}
TrainCrew::~TrainCrew() {
	for (Employee* member : members) {
		delete member;
	}
}

string TrainCrew::getCrewName() const { return crewName; }
int TrainCrew::getTrainNumber() const { return trainNumber; }
string TrainCrew::getRoute() const { return route; }
int TrainCrew::getMembersCount() const {return members.size(); }

void TrainCrew::setCrewName(string CrewName) { crewName = CrewName; }
void TrainCrew::setTrainNumber(int TrainNumber) { trainNumber = TrainNumber; }
void TrainCrew::setRoute(string Route) { route = Route; }

void TrainCrew::addMember(Employee* emp) { members.push_back(emp); }
void TrainCrew::deleteMember(int index) {
	if (index >= 0 && index < members.size()) {
		delete members[index];
		members.erase(members.begin() + index);
	}
}
Employee* TrainCrew::getMember(int index) const {
	if (index >= 0 && index < members.size()) {
		return members[index];
	}
	return nullptr;
}
void TrainCrew::editMember(int index) {
	if (index >= 0 && index < members.size()) {
		int sw;
		cout << "Редактирование сотрудника:\n";
		cout << "\t1. Изменить возраст\n";
		cout << "\t2. Изменить зарплату\n";
		cout << "\t0. Выход в предыдущее меню\n";
		cout << "Ваш выбор: ";
		while (!(cin >> sw) || sw < 0 || sw > 2) {
			cout << "Введено не верное значение, повторите попытку: \n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		switch (sw) {
		case 1: {
			int age;
			cout << "Введите возраст: ";
			while (true) {
				cin >> age;
				if (cin.fail()) {
					cout << "Некорректно введены данные, пожалуйста, повторите попытку: ";
					cin.ignore(1000, '\n');
					cin.clear();
					continue;
				}
				if (age < 21) {
					cout << "К сожалению, мы не можем принять необученного сотрудника, может ему всё же больше 20? ";
					continue;
				}
				break;
			}
			members[index]->setAge(age);
			break;
		}
		case 2: {
			double salary;
			cout << "Введите зарплату: ";
			while (true) {
				cin >> salary;
				if (cin.fail()) {
					cout << "Некорректно введены данные, пожалуйста, повторите попытку: ";
					cin.ignore(1000, '\n');
					cin.clear();
					continue;
				}
				if (salary < 0) {
					cout << "Приятно иметь работника, который за свою работу ещё и доплачивает, но так нельзя. Попробуй ещё раз: ";
					continue;
				}
				break;
			}
			members[index]->setSalary(salary);
			break;
		}
		}
	}
}
void TrainCrew::display() const {
	cout << "+" << setfill('-') << setw(82) << "+\n" << setfill(' ');
	cout.setf(ios::left);
	cout << "|" << setw(80) << crewName << "|\n";
	cout.unsetf(ios::left);
	cout << "+" << setfill('-') << setw(4) << "+" << setw(49) << "+" << setw(8) << "+" << setw(10) << "+" << setw(11) << "+\n" << setfill(' ');
	cout << "|" << setw(3) << "№" << "|" << setw(48) << "ФИО" << "|" << setw(7) << "Возраст" << "|" << setw(9) << "Зарплата" << "|" << setw(9) << "Профессия" << "|\n";
	cout << "+" << setfill('-') << setw(4) << "+" << setw(49) << "+" << setw(8) << "+" << setw(10) << "+" << setw(11) << "+\n" << setfill(' ');
	for (int i = 1; i <= getMembersCount(); i++) {
		cout << "|" << setw(3) << i;
		members[i - 1]->display();
	}
	cout << "+" << setfill('-') << setw(82) << "+\n" << setfill(' ');
}
void TrainCrew::input() {
	cout << "Введите название бригады: ";
	if (cin.peek() == '\n') cin.ignore();
	getline(cin, crewName);
	cout << "Введите номер поезда: ";
	while (true) {
		cin >> trainNumber;
		if (cin.fail()) {
			cout << "Некорректно введены данные, пожалуйста, повторите попытку: ";
			cin.ignore(1000, '\n');
			cin.clear();
			continue;
		}
		if (trainNumber < 0) {
			cout << "Мне кажется, что номера не могут быть отрицательными: ";
			continue;
		}
		break;
	}
	cout << "Введите маршрут: ";
	if (cin.peek() == '\n') cin.ignore();
	getline(cin, route);
}

void TrainCrew::sortByName() { sort(members.begin(), members.end(), [](Employee* a, Employee* b) { return a->getName() < b->getName(); }); }
void TrainCrew::sortByAge() { sort(members.begin(), members.end(), [](Employee* a, Employee* b) { return a->getAge() < b->getAge(); }); }
void TrainCrew::sortBySalary() { sort(members.begin(), members.end(), [](Employee* a, Employee* b) { return a->getSalary() > b->getSalary(); }); }

void TrainCrew::searchByName(const string& Name) const {
	bool found = false;
	for (const Employee* member : members) {
		if (member->getName() == Name) {
			cout << "+" << setfill('-') << setw(4) << "+" << setw(49) << "+" << setw(8) << "+" << setw(10) << "+" << setw(11) << "+\n" << setfill(' ');
			cout << "|" << setw(3) << "№" << "|" << setw(48) << "ФИО" << "|" << setw(7) << "Возраст" << "|" << setw(9) << "Зарплата" << "|" << setw(9) << "Профессия" << "|\n";
			cout << "+" << setfill('-') << setw(4) << "+" << setw(49) << "+" << setw(8) << "+" << setw(10) << "+" << setw(11) << "+\n" << setfill(' ');
			cout << "|   ";
			member->display();
			cout << "+" << setfill('-') << setw(82) << "+\n" << setfill(' ');
			found = true;
		}
	}
	if (!found) cout << "Сотрудники не найдены" << endl;
}
void TrainCrew::searchByPosition(const string& Position) const {
	bool found = false;
	for (const Employee* member : members) {
		if (member->getName() == Position) {
			member->display();
			cout << member->getPosition() << endl;
			found = true;
		}
	}
	if (!found) cout << "Сотрудники не найдены" << endl;
}