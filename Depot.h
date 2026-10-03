#pragma once
#include "TrainCrew.h"
#include <string>
#include <vector>
class Depot {
	std::string depotName;
	std::string address;
	std::vector<TrainCrew*> crews;
public:
	Depot();
	Depot(std::string DepotName, std::string Address);
	~Depot();

	std::string getDepotName() const;
	std::string getAddress() const;
	int getCrewsCount() const;

	void setDepotName(std::string DepotName);
	void setAddress(std::string Address);

	void addCrew(TrainCrew* crew);
	void deleteCrew(int index);
	TrainCrew* getCrew(int index) const;
	void viewAllCrews() const;
	void sortCrews();
	void searchCrew(const std::string& CrewName) const;
	void input();
};