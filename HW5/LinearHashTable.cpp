#include <stdlib.h>
#include "HashEntry.h"
#include "LinearHashTable.h"

LinearHashTable::LinearHashTable() {
	hashTable = new HashEntry*[TABLE_SIZE];
	for(size_t i = 0; i < TABLE_SIZE; i++) {
		hashTable[i] = NULL;
	}
}

int LinearHashTable::get(int mappedValue) {
	int hashValue = mappedValue % TABLE_SIZE;
	while(hashTable[hashValue] != NULL && hashTable[hashValue]->getMappedValue() != mappedValue) {
		hashValue = (hashValue + 1) % TABLE_SIZE;
	}
	if(hashTable[hashValue] == NULL) {
		return -1;
	}
	
	return hashTable[hashValue]->getMappedValue();
}

int LinearHashTable::insert(int mappedValue) {
	int hashValue = mappedValue % TABLE_SIZE;
	int numProbes = 0;
	while(hashTable[hashValue] != NULL && hashTable[hashValue]->getMappedValue() != mappedValue) {
		hashValue = (hashValue + 1) % TABLE_SIZE;
		numProbes++;
	}
	if(hashTable[hashValue] != NULL) {
		delete hashTable[hashValue];
	}
	hashTable[hashValue] = new HashEntry(mappedValue);

	return numProbes;
}

LinearHashTable::~LinearHashTable() {
	for(size_t i = 0; i < TABLE_SIZE; i++) {
		if(hashTable[i] != NULL) {
			delete hashTable[i];
		}
	}
}