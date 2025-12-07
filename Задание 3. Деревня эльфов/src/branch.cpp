#include "branch.h"
#include <algorithm>

Branch::Branch(Branch* parent) : parent(parent), elfName("") {}

void Branch::addChild(Branch* child) {
    if (child) {
        children.push_back(child);
    }
}

Branch* Branch::findElf(const std::string& name) {
    if (!name.empty() && elfName == name) {
        return this;
    }
    for (Branch* child : children) {
        if (child) {
            Branch* result = child->findElf(name);
            if (result) {
                return result;
            }
        }
    }
    return nullptr;
}

// Исправлено: добавлен const
Branch* Branch::getTopBranch() const {
    if (!parent) {
        return nullptr;  // Корень дерева
    }
    if (!parent->parent) {
        return const_cast<Branch*>(this);  // Большая ветвь
    }
    return parent->getTopBranch();  // Рекурсивный подъём
}

int Branch::countNeighbors() const {
    Branch* top = getTopBranch();
    if (!top) return 0;

    int count = 0;

    // Считаем эльфов на средних ветвях
    for (const auto& midBranch : top->children) {
        if (midBranch && !midBranch->elfName.empty()) {
            count++;
        }
    }

    // Учитываем эльфа на большой ветви
    if (!top->elfName.empty()) {  // Исправлено: было elfNewton
        count++;
    }

    // Вычитаем себя
    if (this == top ||
        std::find(top->children.begin(), top->children.end(), this) != top->children.end()) {
        count--;
    }

    return count;
}
