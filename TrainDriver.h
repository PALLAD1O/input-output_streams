#pragma once
#include "Employee.h"
class TrainDriver : public Employee {
	std::string trainType;
	int rollingHours;
public:
	TrainDriver();
	TrainDriver(std::string Name, int Age, double Salary, std::string TrainType, int RollingHours);

	std::string getTrainType() const;
	int getRollingHours() const;

	void setTrainType(std::string TrainType);
	void setRollingHours(int RollingHours);

	std::string getPosition() const override;
	void input() override;
};