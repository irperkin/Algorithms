#include <iostream>
#include <list>
#include <cstdlib>
#include "LinearHashTable.h"

int main (int argc, char* argv[]) {
	LinearHashTable linearTable;
	std::list<int> linearProbes, quadProbes, doubHashProbes;

	srand((unsigned)time(0)); // changing random number seed

	for(int i = 0; i < 900; i++) {
		linearTable.insert(rand()); // inserting first 900 random numbers
		// quadTable.insert(rand());
		// doubHashTable(rand());
	}

	for(int i = 0; i < 50; i++) {
		linearProbes.push_back(linearTable.insert(rand())); // inserting last 50 numbers
		// quadProbes.push_back(quadTable.insert(rand()));
		// doubHashProbes.push_back(doubHashTable(rand()));
	}

	std::cout << "Ayy, it's working." << std::endl;

	return 0;
}
