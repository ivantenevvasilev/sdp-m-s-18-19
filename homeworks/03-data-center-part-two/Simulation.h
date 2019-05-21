struct Order {
	int numberOfStorageUnits;
	Company company;
  
	Order () = default;
	Order (int numberOfStorageUnits, const Company& company)
			: company(company), numberOfStorageUnits(numberOfStorageUnits) {}
};

struct SimulationResult {
	char status; // 's' == success, 'f' == failure
	unsigned int totalDays;
	double finalBudget;
	Queue<Order> unfinishedOrders;
};

const int STORAGE_UNITS_COUNT = 1024;

class Simulation {
	DataCenter dataCenter;
	DynamicArray<Company> companies;
	StorageUnit storageUnits[STORAGE_UNITS_COUNT];

public:
	Queue<Order> getSampleOrders1();
	Queue<Order> getSampleOrders2();
	Queue<Order> getSampleOrders3();

	void prepare();
	// трябва да го имплементирате
	SimulationResult simulate (Queue<Order> orders, int storageUnitsPerUpgrade, int minutesPerStorageUnit);
};
