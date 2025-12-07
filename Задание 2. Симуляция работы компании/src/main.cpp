#include <iostream>
#include <string>
#include <ceo.h>
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread;
using namespace chrono;

int main(){
	setlocale(LC_ALL, "RU");
	int teams, employees;
	cout << "Enter count of teams: "; cin >> teams;
	
	Ceo ceo;
	ceo.setName("Vlad");

	cout << "Enter number of employees per team: ";
	cin >> employees;

	for (int i = 0; i < teams; i++) {
		Manager manager;
		manager.setName("Manager_" + std::to_string(i + 1));
		manager.setId(i + 1);

		for (int s = 0; s < employees; s++) {
			Employee employee;
			employee.setName("Worker_" + to_string(i + 1) + "_" + to_string(s + 1));
			manager.addWorker(employee);
		}

		ceo.addManager(manager);
	}

	cout << "Immulation starts in 3 seconds\n";

	for (int i = 0; i < 3; i++) {
		sleep_for(seconds(1));
		cout << 3 - i << " ";
		sleep_until(system_clock::now() + seconds(1));
	}

	cout << "\n----------------------\n";

	while (true) {
		int command;
		cout << "Enter your command(0 - exit): "; cin >> command;
		
		if (command == 0) {
			cout << "Simulation completed\n";
			return 0;
		}

		ceo.giveTask(command);
	}
}