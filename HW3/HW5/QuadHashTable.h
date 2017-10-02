#ifndef QUAD_HASH_TABLE_H
#define QUAD_HASH_TABLE_H

#include <stdlib.h>

class QuadHashTable {
private:
	int **hashTable;
public:
	QuadHashTable();
	int insert(int mappedValue);
	~QuadHashTable();
};

#endif