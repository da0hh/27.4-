#include <employee.h>

bool Employee::isBusy() { return busy; }

void Employee::setName(const std::string& name) { 
	this->name = name; 
}

std::string Employee::getName() { return name; }

void Employee::receiveWork(TaskType task) {
		busy = true;
		currentTask = task;
}

TaskType Employee::getTask() { return currentTask; }