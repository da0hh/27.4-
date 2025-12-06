#include "manager.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

Manager::Manager(const std::string& name, int teamId)
    : name(name), teamId(teamId) {
}

void Manager::addWorker(const Worker& worker) {
    workers.push_back(worker);
}

void Manager::processCommand(int command) {
    int seed = command + teamId;
    std::srand(seed);

    int tasksCount = std::rand() % workers.size() + 1;
    std::cout << "Manager " << name << " received command " << command
        << " (seed=" << seed << "), will distribute " << tasksCount << " tasks" << std::endl;

    for (int i = 0; i < tasksCount; ++i) {
        bool assigned = false;
        for (auto& worker : workers) {
            if (!worker.isBusy()) {
                TaskType task = static_cast<TaskType>(std::rand() % 3);
                worker.receiveTask(task);
                assigned = true;
                break;
            }
        }
        if (!assigned) {
            std::cout << "All workers in team " << teamId
                << " are busy, cannot assign more tasks" << std::endl;
            break;
        }
    }
}

bool Manager::allWorkersBusy() const {
    return std::all_of(workers.begin(), workers.end(),
        [](const Worker& w) { return w.isBusy(); });
}

const std::string& Manager::getName() const { return name; }
