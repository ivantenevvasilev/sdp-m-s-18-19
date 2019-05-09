#ifndef INC_02__DATA_CENTER_PART_ONE_COMPANY_H
#define INC_02__DATA_CENTER_PART_ONE_COMPANY_H

#include "DynamicArray.h"
#include "StorageUnit.h"

class StorageUnit;

const double TAX_RATE = 0.1;

class Company {
	DynamicArray<char> name;
	double budget;
	DynamicArray<StorageUnit> rentedStorage;

public:
	Company ();

	/* помощни член-функции */
	void addStorage (const StorageUnit& storageUnit);
	double payForUnits();

	bool operator== (const Company& other) const;
};

Company::Company () {
	budget = 0;
}

void Company::addStorage (const StorageUnit& storageUnit) {
	rentedStorage.pushBack(storageUnit);
}

double Company::payForUnits () {
	double money = 0;

	for (unsigned int i = 0, storageSize = rentedStorage.getSize(); i < storageSize; ++i) {
		double cost = TAX_RATE * rentedStorage[i].getCost();
		budget -= cost;
		money += cost;
	}

	return money;
}

bool Company::operator== (const Company& other) const {
	return name == other.name;
}


#endif //INC_02__DATA_CENTER_PART_ONE_COMPANY_H
