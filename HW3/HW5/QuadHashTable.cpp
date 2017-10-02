#include <stdlib.h>
#include "QuadHashTable.h"

const int TABLE_SIZE = 1009;
const int c1 = 1;
const int c2 = 3;

QuadHashTable::QuadHashTable() {
	hashTable = new int*[TABLE_SIZE];
	for(size_t i = 0; i < TABLE_SIZE; i++) {
		hashTable[i] = NULL;
	}
}

int QuadHashTable::insert(int mappedValue) {
	int hashValue = mappedValue % TABLE_SIZE;
	int numProbes = 0;
	for(int i = 1; hashTable[hashValue] != NULL; i++) {
		hashValue = ((mappedValue % TABLE_SIZE) + ((c1*i + c2*i*i) % TABLE_SIZE)) % TABLE_SIZE;
		numProbes++;
	}
	hashTable[hashValue] = new int(mappedValue);

	return numProbes;
}

QuadHashTable::~QuadHashTable() {
	for(size_t i = 0; i < TABLE_SIZE; i++) {
		if(hashTable[i] != NULL) {
			delete hashTable[i];
		}
	}
}