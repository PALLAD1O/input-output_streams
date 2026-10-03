/* В каждом индивидуальном задании необходимо реализовать функции
1. просмотра,
2. добавления,
3. удаления,
4. редактирования,
5. сортировки,
6. поиска данных по необходимым параметрам (с учётом индивидуального задания).
Обязательно использовать минимум 5 флагов форматирования. Сформировать табличный вывод всех данных на экран и в файл.
Использовать функции setf() и unsetf() для установки и сбрасывания флагов форматирования.
Использовать функции eof(), fail(), good(), bad(), clear() для проверки состояния потока.
Разработать набор классов (минимум 5 классов, связи между классами: агрегация, композиция, наследование) по предметной области «Железнодорожные пассажироперевозки».
Функционал программы должен позволить собрать персонал для поездки. */
#include "Employee.h"
#include "TrainDriver.h"
#include "Conductor.h"
#include "TrainCrew.h"
#include "Depot.h"
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;
int mainMenu() {
	int sw;
	cout << "Меню:\n";
	cout << "\t1. Добавить новую бригаду;\n";
	cout << "\t2. Просмотр бригад;\n";
	cout << "\t3. Редактировать бригаду;\n";
	cout << "\t4. Сортировать бригады;\n";
	cout << "\t5. Поиск бригады;\n";
	cout << "\t6. Удалить бригаду;\n";
	cout << "\t0. Выход из программы.\n";
	cout << "Ваш выбор: ";
	while (!(cin >> sw) || sw < 0 || sw > 6) {
		cout << "Введено не верное значение, повторите попытку: \n";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return sw;
}
int secondMenu() {
	int sw;
	cout << "Добавление персонала в бригаду:\n";
	cout << "\t1. Добавить машиниста;\n";
	cout << "\t2. Добавить проводника;\n";
	cout << "\t3. Просмотр всей бригады;\n";
	cout << "\t4. Редактировать данные сотрудника;\n";
	cout << "\t5. Удалить сотрудника;\n";
	cout << "\t6. Сортировать сотрудников;\n";
	cout << "\t7. Поиск сотрудников;\n";
	cout << "\t0. Выход в главное меню.\n";
	cout << "Ваш выбор: ";
	while (!(cin >> sw) || sw < 0 || sw > 7) {
		cout << "Введено не верное значение, повторите попытку: \n";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return sw;
}
int sortMenu() {
	int sw;
	cout << "Сортировать по:\n";
	cout << "\t1. Сортировать по имени (от А до Я);\n";
	cout << "\t2. Сортировать по возрасту (от меньшего к большему);\n";
	cout << "\t3. Сортировать по зарплате (от большей к меньшей);\n";
	cout << "\t0. Выход в предыдущее меню.\n";
	cout << "Ваш выбор: ";
	while (!(cin >> sw) || sw < 0 || sw > 3) {
		cout << "Введено не верное значение, повторите попытку: \n";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return sw;
}
int searchMenu() {
	int sw;
	cout << "Поиск по:\n";
	cout << "\t1. Поиск по имени;\n";
	cout << "\t2. Поиск по профессии;\n";
	cout << "\t0. Выход в предыдущее меню.\n";
	cout << "Ваш выбор: ";
	while (!(cin >> sw) || sw < 0 || sw > 2) {
		cout << "Введено не верное значение, повторите попытку: \n";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return sw;
}
int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	Depot depot = Depot();
	depot.input();
	while (true) {
		system("cls");
		switch (mainMenu()) {
		case 1: {
			TrainCrew* crew = new TrainCrew();
			depot.addCrew(crew);
			crew->input();
			bool Continue = true;
			while (Continue) {
				system("cls");
				switch (secondMenu()) {
				case 1: {
					TrainDriver* trainDriver = new TrainDriver();
					crew->addMember(trainDriver);
					trainDriver->input();
					cout << "Машинист добавлен!";
					_getch();
					break;
				}
				case 2: {
					Conductor* conductor = new Conductor();
					crew->addMember(conductor);
					conductor->input();
					cout << "Проводник добавлен!";
					_getch();
					break;
				}
				case 3:	{
					crew->display();
					_getch();
					break;
				}
				case 4:	{
					int index;
					cout << "Введите номер сотрудника: ";
					while (true) {
						cin >> index;
						if (cin.fail()) {
							cout << "Некорректно введены данные, пожалуйста, повторите попытку: ";
							cin.ignore(1000, '\n');
							cin.clear();
							continue;
						}
						break;
					}
					crew->editMember(index - 1);
					cout << "Данные сотрудника отредактированы!";
					_getch();
					break;
				}
				case 5:	{
					int index;
					cout << "Введите номер сотрудника: ";
					while (true) {
						cin >> index;
						if (cin.fail()) {
							cout << "Некорректно введены данные, пожалуйста, повторите попытку: ";
							cin.ignore(1000, '\n');
							cin.clear();
							continue;
						}
						break;
					}
					crew->deleteMember(index - 1);
					cout << "Сотрудник удалён!";
					_getch();
					break;
				}
				case 6:	{
					switch (sortMenu()) {
					case 1: {
						crew->sortByName();
						cout << "Сотрудники отсортированы!";
						_getch();
						break;
					}
					case 2: {
						crew->sortByAge();
						cout << "Сотрудники отсортированы!";
						_getch();
						break;
					}
					case 3: {
						crew->sortBySalary();
						cout << "Сотрудники отсортированы!";
						_getch();
						break;
					}
					}
					break;
				}
				case 7:	{
					string name;
					cout << "Введите ФИО: ";
					if (cin.peek() == '\n') cin.ignore();
					getline(cin, name);
					crew->searchByName(name);
					_getch();
					break;
				}
				case 0:	{
					Continue = false;
					break;
				}
				}
			}
			break;
		}
		case 2: {
			depot.viewAllCrews();
			_getch();
			break;
		}
		case 3: {
			int index;
			cout << "Введите номер бригады: ";
			while (true) {
				cin >> index;
				if (cin.fail()) {
					cout << "Некорректно введены данные, пожалуйста, повторите попытку: ";
					cin.ignore(1000, '\n');
					cin.clear();
					continue;
				}
				break;
			}
			TrainCrew* crew = depot.getCrew(index - 1);
			if (crew == nullptr) {
				cout << "Нет такой бригады!";
				_getch();
				break;
			}
			bool Continue = true;
			while (Continue) {
				system("cls");
				switch (secondMenu()) {
				case 1: {
					TrainDriver* trainDriver = new TrainDriver();
					crew->addMember(trainDriver);
					trainDriver->input();
					cout << "Машинист добавлен!";
					_getch();
					break;
				}
				case 2: {
					Conductor* conductor = new Conductor();
					crew->addMember(conductor);
					conductor->input();
					cout << "Проводник добавлен!";
					_getch();
					break;
				}
				case 3: {
					crew->display();
					_getch();
					break;
				}
				case 4: {
					int index;
					cout << "Введите номер сотрудника: ";
					while (true) {
						cin >> index;
						if (cin.fail()) {
							cout << "Некорректно введены данные, пожалуйста, повторите попытку: ";
							cin.ignore(1000, '\n');
							cin.clear();
							continue;
						}
						break;
					}
					crew->editMember(index - 1);
					cout << "Данные сотрудника отредактированы!";
					_getch();
					break;
				}
				case 5: {
					int index;
					cout << "Введите номер сотрудника: ";
					while (true) {
						cin >> index;
						if (cin.fail()) {
							cout << "Некорректно введены данные, пожалуйста, повторите попытку: ";
							cin.ignore(1000, '\n');
							cin.clear();
							continue;
						}
						break;
					}
					crew->deleteMember(index - 1);
					cout << "Сотрудник удалён!";
					_getch();
					break;
				}
				case 6: {
					switch (sortMenu()) {
					case 1: {
						crew->sortByName();
						cout << "Сотрудники отсортированы!";
						_getch();
						break;
					}
					case 2: {
						crew->sortByAge();
						cout << "Сотрудники отсортированы!";
						_getch();
						break;
					}
					case 3: {
						crew->sortBySalary();
						cout << "Сотрудники отсортированы!";
						_getch();
						break;
					}
					}
					break;
				}
				case 7: {
					string name;
					cout << "Введите ФИО: ";
					if (cin.peek() == '\n') cin.ignore();
					getline(cin, name);
					crew->searchByName(name);
					_getch();
					break;
				}
				case 0: {
					Continue = false;
					break;
				}
				}
			}
			break;
			_getch();
			break;
		}
		case 4: {
			depot.sortCrews();
			cout << "Бригады отсортированы!";
			_getch();
			break;
		}
		case 5: {
			string crewName;
			cout << "Введите название бригады: ";
			if (cin.peek() == '\n') cin.ignore();
			getline(cin, crewName);
			depot.searchCrew(crewName);
			_getch();
			break;
		}
		case 6: {
			int index;
			cout << "Введите номер бригады: ";
			while (true) {
				cin >> index;
				if (cin.fail()) {
					cout << "Некорректно введены данные, пожалуйста, повторите попытку: ";
					cin.ignore(1000, '\n');
					cin.clear();
					continue;
				}
				break;
			}
			depot.deleteCrew(index - 1);
			cout << "Бригада удалена!";
			_getch();
			break;
		}
		case 0:
			cout << "Программа завершена!";
			return 0;
		}
	}
}