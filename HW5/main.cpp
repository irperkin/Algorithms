#include <iostream>
#include <list>
#include <cstdlib>
#include "LinearHashTable.h"
#include "QuadHashTable.h"
#include "DoubleHashTable.h"

// to compile use: g++ *.cpp

typedef std::list<int> numList;

void printProbes(numList probes) {
	float totalProbes = 0;

	for(numList::iterator iter = probes.begin(); iter != probes.end(); iter++) {
		totalProbes += *iter;
	}
	std::cout << "Average number of probes for the last 50 insertions = " << 1.0*(totalProbes / probes.size()) << std::endl << std::endl;
}

int main (int argc, char* argv[]) {
	LinearHashTable linearTable;
	QuadHashTable quadTable;
	DoubleHashTable doubHashTable;
	numList linearProbes, quadProbes, doubHashProbes;

	srand((unsigned)time(0)); // changing random number seed

	for(int i = 0; i < 900; i++) {
		linearTable.insert(rand()); // inserting first 900 random numbers
		quadTable.insert(rand());
		doubHashTable.insert(rand());
	}

	for(int i = 0; i < 50; i++) {
		linearProbes.push_back(linearTable.insert(rand())); // inserting last 50 numbers
		quadProbes.push_back(quadTable.insert(rand()));
		doubHashProbes.push_back(doubHashTable.insert(rand()));
	}

	std::cout << std::endl;

	std::cout << "Linear Probing: " << std::endl;
	printProbes(linearProbes);

	std::cout << "Quadratic Probing: " << std::endl;
	printProbes(quadProbes);

	std::cout << "Double Hashing: " << std::endl;
	printProbes(doubHashProbes);

	return 0;
}
