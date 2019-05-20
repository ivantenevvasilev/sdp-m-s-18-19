#ifndef INC_02__DATA_CENTER_PART_ONE_COMPANY_H
#define INC_02__DATA_CENTER_PART_ONE_COMPANY_H

#include <cstring>

#include "DynamicArray.h"
#include "StorageUnit.h"

class StorageUnit;

const double TAX_RATE = 0.1;

class Company {
	char name[1024];
	double budget;
	DynamicArray<StorageUnit> rentedStorage;

public:
	Company ();

	/* помощни член-функции */
	void addStorage (const StorageUnit& storageUnit);
	double payForUnits();

	bool operator== (const Company& other) const;
};

#endif //INC_02__DATA_CENTER_PART_ONE_COMPANY_H
