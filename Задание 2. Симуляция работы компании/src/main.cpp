#include <ceo.h>
#include <worker.h>
#include <manager.h>

using namespace std;

int main() {
    int numTeams, numWorkersPerTeam;

    std::cout << "Enter number of teams: ";
    std::cin >> numTeams;
    std::cout << "Enter number of workers per team: ";
    std::cin >> numWorkersPerTeam;

    CEO ceo("Alice");

    for (int i = 0; i < numTeams; ++i) {
        Manager manager("Manager_" + std::to_string(i + 1), i + 1);

        for (int j = 0; j < numWorkersPerTeam; ++j) {
            Worker worker("Worker_" + std::to_string(i + 1) + "_" + std::to_string(j + 1));
            manager.addWorker(worker);
        }

        ceo.addManager(manager);
    }

    std::cout << "Simulation started. Enter CEO commands (integers). Enter 0 to exit.\n";

    int command;
    while (true) {
        std::cout << "\nEnter command: ";
        std::cin >> command;

        if (command == 0) {
            std::cout << "Exiting simulation.\n";
            break;
        }

        ceo.issueCommand(command);

        if (ceo.allEmployeesBusy()) {
            std::cout << "\nAll employees are busy. Simulation completed.\n";
            break;
        }
    }

    return 0;
}