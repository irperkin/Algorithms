#include <stdlib.h>
#include "QuadHashTable.h"

QuadHashTable::QuadHashTable() {
	hashTable = new int*[TABLE_SIZE];
	for(size_t i = 0; i < TABLE_SIZE; i++) {
		hashTable[i] = NULL;
	}
}

int QuadHashTable::get(int mappedValue) {
	int hashValue = mappedValue % TABLE_SIZE;
	for(int i = 1; hashTable[hashValue] != NULL && *hashTable[hashValue] != mappedValue; i++) {
		hashValue = (mappedValue + c1*1 + c2*i*i) % TABLE_SIZE;
	}
	if(hashTable[hashValue] == NULL) {
		return -1;
	}

	return *hashTable[hashValue];
}

int QuadHashTable::insert(int mappedValue) {
	int hashValue = mappedValue % TABLE_SIZE;
	int numProbes;
	for(int i = 1; hashTable[hashValue] != NULL && *hashTable[hashValue] != mappedValue; i++) {
		hashValue = (mappedValue + c1*i + c2*i*i) % TABLE_SIZE;
		numProbes++;
	}
	if(hashTable[hashValue] != NULL) {
		delete hashTable[hashValue];
	}
	hashTable[hashValue] = new int (mappedValue);

	return numProbes;
}

QuadHashTable::~QuadHashTable() {
	for(size_t i = 0; i < TABLE_SIZE; i++) {
		if(hashTable[i] != NULL) {
			delete hashTable[i];
		}
	}
}