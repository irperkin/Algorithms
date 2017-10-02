#include <stdlib.h>
#include <iostream>
#include "LinearHashTable.h"

const int TABLE_SIZE = 1009;

LinearHashTable::LinearHashTable() {
	hashTable = new int*[TABLE_SIZE];
	for(size_t i = 0; i < TABLE_SIZE; i++) {
		hashTable[i] = NULL;
	}
}

int LinearHashTable::insert(int mappedValue) {
	int hashValue = mappedValue % TABLE_SIZE;
	int numProbes = 0;
	while(hashTable[hashValue] != NULL) {
		hashValue = (hashValue + 1) % TABLE_SIZE;
		numProbes++;
	}
	if(hashTable[hashValue] != NULL) {
		delete hashTable[hashValue];
	}
	hashTable[hashValue] = new int(mappedValue);

	return numProbes;
}

LinearHashTable::~LinearHashTable() {
	for(size_t i = 0; i < TABLE_SIZE; i++) {
		if(hashTable[i] != NULL) {
			delete hashTable[i];
		}
	}
}
