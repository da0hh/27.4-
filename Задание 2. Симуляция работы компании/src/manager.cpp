#include "manager.h"
#include <iostream>

void Manager::setName(const std::string& name) {
	this->name = name;
}

void Manager::addWorker(const Employee& employee) {
	workers.push_back(employee);
}

void Manager::setId(int id) { 
	this->id = id; 
}

void Manager::setTask(int command) {
	int seed = command + id;
	srand(seed);
	int tasks = rand() % workers.size() + 1;

	for (size_t i = 0; i < workers.size(); i++) {
		if (!workers[i].isBusy()) {
			TaskType task = static_cast<TaskType>(rand() % 3);
			workers[i].receiveWork(task);

			const char* taskNames = "ABC";
			char taskChar = taskNames[static_cast<int>(task)];

			std::cout << "Worker " << workers[i].getName() << " get task " << taskChar << std::endl;

			tasks--;
			if (tasks == 0) { break; }
		}
	}
	if (tasks > 0) {
		std::cout << "Warning: " << tasks << " tasks undistributed (all workers busy)\n";
	}
}