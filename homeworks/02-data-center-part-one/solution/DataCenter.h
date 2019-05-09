#ifndef INC_02__DATA_CENTER_PART_ONE_DATACENTER_H
#define INC_02__DATA_CENTER_PART_ONE_DATACENTER_H

#include "DynamicArray.h"
#include "StorageUnit.h"
#include "Company.h"


class DataCenter {
	double budget;
	DynamicArray<StorageUnit> storage;
	DynamicArray<Company> clients;

public:
	void lendStorageTo (const Company& company);
	void taxClients ();
	void upgradeStorage (const DynamicArray<StorageUnit>& disks);
};

void DataCenter::lendStorageTo (const Company& company) {
	StorageUnit* freeUnit = nullptr;

	for (unsigned int i = 0, storageSize = storage.getSize(); i < storageSize; ++i) {
		if (storage[i].getOwner() == nullptr) {
			freeUnit = &storage[i];
			break;
		}
	}

	if (freeUnit != nullptr) {
		Company* targetClient = nullptr;
		unsigned int clientsSize = clients.getSize();

		for (unsigned int i = 0; i < clientsSize; ++i) {
			if (clients[i] == company) {
				targetClient = &clients[i];
			}
		}

		if (targetClient == nullptr) {
			clients.pushBack(company);
			targetClient = &clients[clientsSize];
		}

		targetClient->addStorage(*freeUnit);
	}
}

void DataCenter::taxClients () {
	for (unsigned int i = 0, clientsSize = clients.getSize(); i < clientsSize; ++i) {
		budget += clients[i].payForUnits();
	}
}

void DataCenter::upgradeStorage (const DynamicArray <StorageUnit>& disks) {
	for (unsigned int i = 0, disksSize = disks.getSize(); i < disksSize; ++i) {
		storage.pushBack(disks[i]);
	}
}


#endif //INC_02__DATA_CENTER_PART_ONE_DATACENTER_H
