#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <vector>
#include <sstream>

using namespace std;

class Activity {
public:
	int id;
	int startTime;
	int endTime;
	int value;
	Activity(int, int, int, int);
	void print();
};

Activity::Activity(int id, int startTime, int endTime, int value) {
	this->id = id;
	this->startTime = startTime;
	this->endTime = endTime;
	this->value = value;
}

void Activity::print() {
	cout << "id = " << this->id << ", ";
	cout << "startTime = " << this->startTime << ", ";
	cout << "endTime = " << this->endTime << ", ";
	cout << "value = " << this->value << endl;
}

string stringTokenizer(string &s, string delimiter) {
	size_t pos = 0;
	string token;

	if ((pos = s.find(delimiter)) != string::npos) {
	    token = s.substr(0, pos);
	    s.erase(0, pos + delimiter.length());
	} else {
		token = s;
		s.clear();
	}
	return token;
}

void readInputFile(char * inputFile, vector<Activity> &activities) {
	ifstream inStream(inputFile);
	string line, temp;
	vector<int> activityValues;

	if(inStream.is_open()) {
		while(getline(inStream, line)) {
			while(line.length() != 0) {
				activityValues.push_back(atoi(stringTokenizer(line, " ").c_str()));
			}
			if(temp.empty()) {
				temp = activityValues[0];
				activityValues.clear();
			}
			activities.push_back(Activity(activityValues[0], activityValues[1], activityValues[2], activityValues[3]));
			activityValues.clear();
		}
	}
}

void activitySelector() {
	
}

int main(int argc, char * argv[]) {

	if(argc != 3) {
		cout << "USAGE: ./a.out input.txt output.txt" << endl;
		return -1;
 	}

 	char * inputFile = argv[1];
 	char * outputFile = argv[2];
 	vector<Activity> activities;

 	readInputFile(inputFile, activities);

	// testing ssh key 	

	return 0;
}
