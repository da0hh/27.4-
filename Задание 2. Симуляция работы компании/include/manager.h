#include "employee.h"
#include <vector>
#include <string>
#pragma once

class Manager {
	std::string name;
	int id;
	std::vector<Employee> workers;

public:
	void setName(const std::string& name);
	void addWorker(const Employee& employee);
	void setId(int id);
	void setTask(int command);
};