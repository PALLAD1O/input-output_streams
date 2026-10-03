#pragma once
#include "Employee.h"
#include <iostream>
#include <string>
#include <vector>
class TrainCrew {
	std::string crewName;
	int trainNumber;
	std::string route;
	std::vector<Employee*> members;
public:
	TrainCrew();
	TrainCrew(std::string CrewName, int TrainNumber, std::string Route);
	~TrainCrew();

	std::string getCrewName() const;
	int getTrainNumber() const;
	std::string getRoute() const;
	int getMembersCount() const;

	void setCrewName(std::string CrewName);
	void setTrainNumber(int TrainNumber);
	void setRoute(std::string Route);

	void addMember(Employee* emp);
	void deleteMember(int index);
	Employee* getMember(int index) const;
	void editMember(int index);
	void display() const;
	void input();

	void sortByName();
	void sortByAge();
	void sortBySalary();

	void searchByName(const std::string& Name) const;
	void searchByPosition(const std::string& Position) const;
};