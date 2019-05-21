#include <iostream>
#include "headers/Simulation.h"

void printResult(SimulationResult result) {
	std::cout << "status: " << result.status << ", totalDays: " << result.totalDays << ", finalBudget: "
	          << result.finalBudget << std::endl;

	if (result.status == 'f') {
		std::cout << "unfinished orders: " << std::endl;
		while (!result.unfinishedOrders.empty()) {
			Order order;
			result.unfinishedOrders.pop(order);

			std::cout << "    Company: " << order.company.getName()
			          << ", requested units: " << order.numberOfStorageUnits << std::endl;

		}
	}
}

int main () {
	Simulation simulation;

	std::cout << "---- First simulation ----" << std::endl;

	simulation.prepare();
	printResult(simulation.simulate(simulation.getSampleOrders1(), 21, 1));

	std::cout << std::endl << "---- Second simulation ----" << std::endl;

	simulation.prepare();
	printResult(simulation.simulate(simulation.getSampleOrders2(), 40, 1));

	std::cout << std::endl << "---- Third simulation ----" << std::endl;

	simulation.prepare();
	printResult(simulation.simulate(simulation.getSampleOrders3(), 150, 40));

	std::cout << std::endl << "---- Fourth simulation ----" << std::endl;

	simulation.prepare();
	printResult(simulation.simulate(simulation.getSampleOrders2(), 20, 1));

	return 0;
}