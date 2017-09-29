#ifndef HASH_ENTRY_H
#define HASH_ENTRY_H

class HashEntry {
private:
	int key;
	int mappedValue;
public:
	HashEntry(int key, int mappedValue);
	int getKey();
	int getMappedValue();
};

#endif