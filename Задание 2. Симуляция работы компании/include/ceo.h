#pragma once
#include <vector>
#include <string>
#include "manager.h"
#include <iostream>

class CEO {
private:
    std::string name;
    std::vector<Manager> managers;
public:
    CEO(const std::string& name);
    void addManager(const Manager& manager);
    void issueCommand(int command);
    bool allEmployeesBusy() const;
    const std::string& getName() const;
};