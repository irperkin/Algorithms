#ifndef QUAD_HASH_TABLE_H
#define QUAD_HASH_TABLE_H

#include <stdlib.h>
#include "HashEntry.h"

const int TABLE_SIZE = 1009;
const int c1 = 1;
const int c2 = 3;

class QuadHashTable {
private:
	HashEntry **hashTable;
public:
	QuadHashTable();
	int get(int mappedValue);
	int insert(int mappedValue);
	~QuadHashTable();
};

#endif