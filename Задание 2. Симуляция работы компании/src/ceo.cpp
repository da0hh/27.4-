#include "ceo.h"
#include <algorithm>

CEO::CEO(const std::string& name) : name(name) {}

void CEO::addManager(const Manager& manager) {
    managers.push_back(manager);
}

void CEO::issueCommand(int command) {
    std::cout << "CEO " << name << " issued command: " << command << std::endl;
    for (auto& manager : managers) {
        manager.processCommand(command);
    }
}

bool CEO::allEmployeesBusy() const {
    return std::all_of(managers.begin(), managers.end(),
        [](const Manager& m) { return m.allWorkersBusy(); });
}

const std::string& CEO::getName() const { return name; }
