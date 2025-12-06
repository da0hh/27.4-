#pragma once
#include <vector>
#include <string>
#include "worker.h"

class Manager {
private:
    std::string name;
    std::vector<Worker> workers;
    int teamId;
public:
    Manager(const std::string& name, int teamId);
    void addWorker(const Worker& worker);
    void processCommand(int command);
    bool allWorkersBusy() const;
    const std::string& getName() const;
};

