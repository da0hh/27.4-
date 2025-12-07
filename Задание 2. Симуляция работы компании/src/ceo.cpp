#include <ceo.h>


void Ceo::addManager(const Manager& manager) {
	managers.push_back(manager);
}
void Ceo::setName(const std::string& name) { this->name = name; }

void Ceo::giveTask(int task) {
	for (auto& manager : managers) {
		manager.setTask(task);
	}
}