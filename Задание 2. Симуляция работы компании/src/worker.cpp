#include "worker.h"
#include <iostream>

Worker::Worker(const std::string& name) : name(name) {}

void Worker::receiveTask(TaskType task) {
    if (!busy) {
        busy = true;
        char taskChar = static_cast<char>(task) + 'A';
        std::cout << "Worker " << name << " received task " << taskChar << std::endl;
    }
}

bool Worker::isBusy() const { return busy; }

const std::string& Worker::getName() const { return name; }
