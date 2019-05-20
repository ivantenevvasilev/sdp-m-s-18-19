struct Order {
	int numberOfStorageUnits;
	Company company;

	Order (int numberOfStorageUnits, const Company& company)
			: company(company), numberOfStorageUnits(numberOfStorageUnits) {}
};

struct SimulationResult {
	char status; // 's' == success, 'f' == failure
	unsigned int totalDays;
	double finalBudget;
	std::queue<Order> unfinishedOrders;
};

const int STORAGE_UNITS_COUNT = 1024;

class Simulation {
	DataCenter dataCenter;
	DynamicArray<Company> companies;
	StorageUnit storageUnits[STORAGE_UNITS_COUNT];

public:
	std::queue<Order> getSampleOrders1();
	std::queue<Order> getSampleOrders2();
	std::queue<Order> getSampleOrders3();

	void prepare();
	// трябва да го имплементирате
	SimulationResult simulate (std::queue<Order> orders, int storageUnitsPerUpgrade, int minutesPerStorageUnit);
};
