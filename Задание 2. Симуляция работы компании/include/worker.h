#pragma once
#include <string>

enum class TaskType { A, B, C };

class Worker {
private:
    std::string name;
    bool busy = false;
public:
    Worker(const std::string& name);
    void receiveTask(TaskType task);
    bool isBusy() const;
    const std::string& getName() const;
};
