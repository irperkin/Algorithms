#include "HashEntry.h"

HashEntry::HashEntry(int mappedValue) {
	this->mappedValue = mappedValue;
}

int HashEntry::getMappedValue() {
	return mappedValue;
}