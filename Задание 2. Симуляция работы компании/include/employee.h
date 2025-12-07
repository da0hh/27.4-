#include <string>
#pragma once

enum class TaskType{ A, B, C};

class Employee {
	std::string name = "None";
	bool busy = false;
	TaskType currentTask;

public:
	bool isBusy();
	void setName(const std::string& name);
	std::string getName();
	void receiveWork(TaskType task);
	TaskType getTask();
};