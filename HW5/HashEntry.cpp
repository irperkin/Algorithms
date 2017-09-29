#include "HashEntry.h"

HashEntry::HashEntry(int key, int mappedValue) {
	this->key = key;
	this->mappedValue = mappedValue;
}

int HashEntry::getKey() {
	return key;
}

int HashEntry::getMappedValue() {
	return mappedValue;
}