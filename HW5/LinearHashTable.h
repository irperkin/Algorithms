#ifndef LINEAR_HASH_TABLE_H
#define LINEAR_HASH_TABLE_H

#include <stdlib.h>
#include "HashEntry.h"

const int TABLE_SIZE = 1009;

class LinearHashTable {
private:
	HashEntry **hashTable;
public:
	LinearHashTable();
	int get(int key);
	int insert(int key, int mappedValue);
	~LinearHashTable();
};

#endif