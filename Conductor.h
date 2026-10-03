#pragma once
#include "Employee.h"
class Conductor : public Employee {
	int wagonNumber;
	std::string shift;
public:
	Conductor();
	Conductor(std::string Name, int Age, double Salary, int WagonNumber, std::string Shift);

	int getWagonNumber() const;
	std::string getShift() const;

	void setWagonNumber(int WagonNumber);
	void setShift(std::string Shift);

	std::string getPosition() const override;
	void input() override;
};