#ifndef DOUBLE_HASH_TABLE_H
#define DOUBLE_HASH_TABLE_H

#include <stdlib.h>

class DoubleHashTable {
private:
	int **hashTable;
public:
	DoubleHashTable();
	int get(int mappedValue);
	int insert(int mappedValue);
	~DoubleHashTable();
};

#endif