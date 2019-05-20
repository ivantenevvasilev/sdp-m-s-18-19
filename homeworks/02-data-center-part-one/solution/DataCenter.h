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

#endif //INC_02__DATA_CENTER_PART_ONE_DATACENTER_H
