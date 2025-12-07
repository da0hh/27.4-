#include "manager.h"
#include <vector>
#include <string>
#pragma once

class Ceo {
	std::string name;
	std::vector<Manager> managers;

public:
	void addManager(const Manager& manager);
	void setName(const std::string& name);
	void giveTask(int task);
};