#include "Depot.h"
#include <algorithm>
#include <iostream>
using namespace std;
Depot::Depot() : depotName(""), address("") {}
Depot::Depot(string DepotName, string Address) : depotName(DepotName), address(Address) {}
Depot::~Depot() { for (TrainCrew* crew : crews) delete crew; }

string Depot::getDepotName() const { return depotName; }
string Depot::getAddress() const { return address; }
int Depot::getCrewsCount() const { return crews.size(); }

void Depot::setDepotName(string DepotName) { depotName = DepotName; }
void Depot::setAddress(string Address) { address = Address; }

void Depot::addCrew(TrainCrew* crew) { crews.push_back(crew); }
void Depot::deleteCrew(int index) {
    if (index >= 0 && index < crews.size()) {
        delete crews[index];
        crews.erase(crews.begin() + index);
    }
}
TrainCrew* Depot::getCrew(int index) const {
    if (index >= 0 && index < crews.size()) {
        return crews[index];
    }
    return nullptr;
}
void Depot::viewAllCrews() const {
    cout << "ДЕПО: " << depotName << endl;
    cout << "Адрес: " << address << endl;
    if (crews.empty()) {
        cout << "Бригад нет" << endl;
        return;
    }
    int j = 1;
    for (const TrainCrew* crew : crews) {
        cout << j++ << "." << endl;
        crew->display();
    }
}
void Depot::sortCrews() { sort(crews.begin(), crews.end(), [](TrainCrew* a, TrainCrew* b) {return a->getCrewName() < b->getCrewName(); }); }
void Depot::searchCrew(const string& CrewName) const {
    bool found = false;
    for (const TrainCrew* crew : crews) {
        if (crew->getCrewName() == CrewName) {
            crew->display();
            found = true;
        }
    }
    if (!found) cout << "Бригада не найдена" << endl;
}
void Depot::input() {
    cout << "Введите название ДЕПО: ";
    if (cin.peek() == '\n') cin.ignore();
    getline(cin, depotName);
    cout << "Введите адрес ДЕПО: ";
    if (cin.peek() == '\n') cin.ignore();
    getline(cin, address);
}