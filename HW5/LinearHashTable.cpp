#include <stdlib.h>
#include "HashEntry.h"
#include "LinearHashTable.h"

LinearHashTable::LinearHashTable() {
	hashTable = new HashEntry*[TABLE_SIZE];
	for(size_t i = 0; i < TABLE_SIZE; i++) {
		hashTable[i] = NULL;
	}
}

int LinearHashTable::get(int key) {
	int hashValue = key % TABLE_SIZE;
	while(hashTable[hashValue] != NULL && hashTable[hashValue]->getKey() != key) {
		hashValue = (hashValue + 1) % TABLE_SIZE;
	}
	if(hashTable[hashValue] == NULL) {
		return -1;
	}
	
	return hashTable[hashValue]->getMappedValue();
}

int LinearHashTable::insert(int key, int mappedValue) {
	int hashValue = key % TABLE_SIZE;
	int numProbes = 0;
	while(hashTable[hashValue] != NULL && hashTable[hashValue]->getKey() != key) {
		hashValue = (hashValue + 1) % TABLE_SIZE;
		numProbes++;
	}
	if(hashTable[hashValue] != NULL) {
		delete hashTable[hashValue]; // overwriting mapped value that matches key given
	}
	hashTable[hashValue] = new HashEntry(key, mappedValue);

	return numProbes;
}

LinearHashTable::~LinearHashTable() {
	for(size_t i = 0; i < TABLE_SIZE; i++) {
		if(hashTable[i] != NULL) {
			delete hashTable[i];
		}
		// delete[] hashTable;
	}
}