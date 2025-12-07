#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "branch.h"

int randomInt(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// Безопасное удаление дерева
void deleteTree(Branch* node) {
    if (!node) return;

    std::vector<Branch*> stack;
    stack.push_back(node);

    while (!stack.empty()) {
        Branch* current = stack.back();
        stack.pop_back();

        for (auto child : current->children) {
            if (child) {
                stack.push_back(child);
            }
        }
        delete current;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    std::vector<Branch*> trees;

    // Генерация 5 деревьев
    for (int i = 0; i < 5; ++i) {
        Branch* tree = new Branch(nullptr);

        int numBigBranches = randomInt(3, 5);
        for (int j = 0; j < numBigBranches; ++j) {
            Branch* bigBranch = new Branch(tree);
            tree->addChild(bigBranch);

            int numMidBranches = randomInt(2, 3);
            for (int k = 0; k < numMidBranches; ++k) {
                Branch* midBranch = new Branch(bigBranch);
                bigBranch->addChild(midBranch);
            }
        }
        trees.push_back(tree);
    }

    // Заселение эльфов
    std::cout << "Заселение эльфов. Введите имена или 'None' для пустого дома.\n";

    for (size_t treeIdx = 0; treeIdx < trees.size(); ++treeIdx) {
        Branch* tree = trees[treeIdx];
        for (size_t i = 0; i < tree->children.size(); ++i) {
            Branch* bigBranch = tree->children[i];

            std::string name;
            std::cout << "Дерево " << (treeIdx + 1)
                << ", большая ветвь " << (i + 1) << ": ";
            std::cin >> name;
            if (name != "None") {
                bigBranch->elfName = name;
            }

            for (size_t j = 0; j < bigBranch->children.size(); ++j) {
                Branch* midBranch = bigBranch->children[j];
                std::cout << "Дерево " << (treeIdx + 1)
                    << ", средняя ветвь " << (i + 1) << "-" << (j + 1) << ": ";
                std::cin >> name;
                if (name != "None") {
                    midBranch->elfName = name;
                }
            }
        }
    }

    // Поиск эльфа
    std::string targetName;
    std::cout << "\nИмя эльфа для поиска: ";
    std::cin >> targetName;

    Branch* foundElf = nullptr;
    for (auto tree : trees) {
        foundElf = tree->findElf(targetName);
        if (foundElf) break;
    }

    if (!foundElf) {
        std::cout << "Эльф " << targetName << " не найден.\n";
    }
    else {
        int neighbors = foundElf->countNeighbors();
        std::cout << "У эльфа " << targetName
            << " " << neighbors << " соседей на большой ветви.\n";
    }

    // Освобождение памяти
    for (auto tree : trees) {
        deleteTree(tree);
    }

    return 0;
}
