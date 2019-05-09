#ifndef INC_02__DATA_CENTER_PART_ONE_STORAGEUNIT_H
#define INC_02__DATA_CENTER_PART_ONE_STORAGEUNIT_H


#include "Company.h"

unsigned int idCounter = 0;

class Company;

class StorageUnit {
	unsigned int id;
	double pricePerGB;
	unsigned int gigabytes;
	Company* owner;

public:
	StorageUnit ();

	Company* getOwner();
	double getCost ();
};

StorageUnit::StorageUnit () {
	id = idCounter;
	++idCounter;
	pricePerGB = 0;
	gigabytes = 0;
	owner = nullptr;
}

Company* StorageUnit::getOwner () {
	return owner;
}

double StorageUnit::getCost () {
	return pricePerGB * gigabytes;
}

#endif //INC_02__DATA_CENTER_PART_ONE_STORAGEUNIT_H
