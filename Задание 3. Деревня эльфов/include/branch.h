#pragma once
#include <string>
#include <vector>

class Branch {
public:
    Branch* parent;
    std::vector<Branch*> children;
    std::string elfName;

    explicit Branch(Branch* parent);
    ~Branch() = default;

    void addChild(Branch* child);
    Branch* findElf(const std::string& name);
    Branch* getTopBranch() const;  // Добавлено const
    int countNeighbors() const;
};
