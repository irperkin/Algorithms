#include <stdlib.h>
#include "DoubleHashTable.h"

const int TABLE_SIZE = 1009;

DoubleHashTable::DoubleHashTable() {
	hashTable = new int *[TABLE_SIZE];
	for(int i = 0; i < TABLE_SIZE; i++) {
		hashTable[i] = NULL;
	}
}

int DoubleHashTable::insert(int mappedValue) {
	int hashValue = mappedValue % TABLE_SIZE;
	int numProbes = 0;
	for(int i = 0; hashTable[hashValue] != NULL; i++) {
		hashValue = ((mappedValue % TABLE_SIZE) + i*((mappedValue % (TABLE_SIZE - 1)) + 1)) % TABLE_SIZE;
		numProbes++;
	}
	hashTable[hashValue] = new int(mappedValue);

	return numProbes;
}

DoubleHashTable::~DoubleHashTable() {
	for(size_t i = 0; i < TABLE_SIZE; i++) {
		if(hashTable[i] != NULL) {
			delete hashTable[i];
		}
	}
}
