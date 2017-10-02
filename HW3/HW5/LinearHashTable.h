#ifndef LINEAR_HASH_TABLE_H
#define LINEAR_HASH_TABLE_H

#include <stdlib.h>

class LinearHashTable {
private:
	int **hashTable;
public:
	LinearHashTable();
	int insert(int mappedValue);
	~LinearHashTable();
};

#endif