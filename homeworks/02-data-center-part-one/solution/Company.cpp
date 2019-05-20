// Разделянето на дефинициите на член-функциите на Company в отделен файл позволява
// цикличната зависимост между Company и StorageUnit да не прави проблем.
#include <cstring>

#include "Company.h"


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
	return strcmp(name, other.name) == 0;
}
