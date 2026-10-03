#include "Employee.h"
#include <iostream>
#include <iomanip>
using namespace std;
Employee::Employee() : name(""), age(0), salary(0.0) {}
Employee::Employee(string Name, int Age, double Salary) : name(Name), age(Age), salary(Salary) {}
Employee::~Employee() {}

string Employee::getName() const { return name; }
int Employee::getAge() const { return age; }
double Employee::getSalary() const { return salary; }

void Employee::setName(string Name) { name = Name; }
void Employee::setAge(int Age) { age = Age; }
void Employee::setSalary(double Salary) { salary = Salary; }

void Employee::display() const { cout << "|" << setw(48) << name << "|" << setw(7) << age << "|" << setw(9) << salary << "|" << setw(9) << getPosition() << "|\n"; }
void Employee::input() {
	cout << "Введите ФИО: ";
	if (cin.peek() == '\n') cin.ignore();
	getline(cin, name);
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
}