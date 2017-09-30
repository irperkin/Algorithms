#ifndef HASH_ENTRY_H
#define HASH_ENTRY_H

class HashEntry {
private:
	int mappedValue;
public:
	HashEntry(int mappedValue);
	int getMappedValue();
};

#endif