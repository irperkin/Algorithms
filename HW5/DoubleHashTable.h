#ifndef DOUBLE_HASH_TABLE_H
#define DOUBLE_HASH_TABLE_H

#include <stdlib.h>

class DoubleHashTable {
private:
	int **hashTable;
public:
	DoubleHashTable();
	int insert(int mappedValue);
	~DoubleHashTable();
};

#endif