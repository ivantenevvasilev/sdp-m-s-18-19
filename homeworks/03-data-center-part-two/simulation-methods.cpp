void Simulation::prepare () {
	companies = DynamicArray<Company>();
	companies.pushBack(Company("ABC", 163868));
	companies.pushBack(Company("Google", 235781));
	companies.pushBack(Company("Microsoft", 102140));
	companies.pushBack(Company("FMI", 62100));
	companies.pushBack(Company("Bell", 21747));
	companies.pushBack(Company("Dell", 131897));
	companies.pushBack(Company("Github", 131897));
	companies.pushBack(Company("SpaceX", 140318));
	companies.pushBack(Company("KickStarter", 139560));
	companies.pushBack(Company("Samsung", 153655));

	for (int i = 0; i < STORAGE_UNITS_COUNT; ++i) {
		storageUnits[i] = StorageUnit(1, (floor(i / 128.0) + 1) * 128);
	}

	dataCenter = DataCenter(30312);
}

std::queue<Order> Simulation::getSampleOrders1 () {
	std::queue<Order> result;

	for (int i = 0; i < 10; ++i) {
		int j = i + 90;
		result.push(Order((j * j * j) % 20 + 12, companies[i]));
	}

	return result;
}

std::queue<Order> Simulation::getSampleOrders2 () {
	std::queue<Order> result;

	for (int i = 0; i < 10; ++i) {
		int j = i + 90;
		result.push(Order((j * j * j) % 100 + 1, companies[i]));
	}

	return result;
}

std::queue<Order> Simulation::getSampleOrders3 () {
	std::queue<Order> result;

	result.push(Order(8, companies[1]));
	result.push(Order(68, companies[2]));

	return result;
}
