#pragma once
#include <string>
#include <iostream>
class Employee {
	std::string name;
	int age;
	double salary;
public:
	Employee();
	Employee(std::string Name, int Age, double Salary);
	virtual ~Employee();

	std::string getName() const;
	int getAge() const;
	double getSalary() const;

	void setName(std::string Name);
	void setAge(int Age);
	void setSalary(double Salary);

	void display() const;
	virtual std::string getPosition() const = 0;
	virtual void input();
};