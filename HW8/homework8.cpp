#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <algorithm>

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
			} else {
				activities.push_back(Activity(activityValues[0], activityValues[1], activityValues[2], activityValues[3]));
			}
			activityValues.clear();
		}
	}
}

bool finishTimeSort(const Activity i, const Activity j) { return (i.endTime < j.endTime); }

// this could be improved with binary search i think
int activitySearch(vector<Activity> activities, int i) {
    for(int j = i - 1; j >= 0; j--) {
        if(activities[j].endTime <= activities[i].startTime) {
            return j;
        }
    }
    return -1;
}

pair<vector<int>, int> weightedActivitySelector(vector<Activity> &activities) {
    int numActivities = activities.size();
    vector<int> temp;
	sort(activities.begin(), activities.end(), finishTimeSort);

	pair<vector<int>, int> * table = new pair<vector<int>, int>[numActivities];
	temp.push_back(activities[0].id);
	table[0] = make_pair(temp, activities[0].value);
	temp.clear();

	cout << "activities[0].id = " << activities[0].id << endl;
	cout << "table[0].first[0] = " << table[0].first[0] << endl;

	for(int i = 1; i < numActivities; i++) {
		temp.push_back(activities[i].id);
        pair<vector<int>, int> vals = make_pair(temp, activities[i].value);
        temp.clear();
        int activity = activitySearch(activities, i);
        if(activity != -1) {
			temp.reserve(vals.first.size() + table[activity].first.size()); // preallocate memory
			temp.insert(temp.end(), vals.first.begin(), vals.first.end());
			temp.insert(temp.end(), table[activity].first.begin(), table[activity].first.end());
        	vals.first = temp;
        	vals.second += table[activity].second;
        	temp.clear();
        }
       	table[i] = (vals.second >= table[i - 1].second ? vals : table[i - 1]);
	}
 	pair<vector<int>, int> result = table[numActivities - 1];
	delete[] table;
	sort(result.first.begin(), result.first.end(), less<int>());
	return result;
}

void writeOutputFile(char * outputFile, pair<vector<int>, int> result) {
	ofstream outStream(outputFile);	

	outStream << "biggest value = " << result.second << endl << "activity id's: ";
 	for(int i = 0; i < result.first.size(); i++) {
 		if(i != result.first.size() - 1) {
 			outStream << result.first[i] << ", ";
 		} else {
 			outStream << result.first[i] << endl;
 		}
 	}
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
 	pair<vector<int>, int> result = weightedActivitySelector(activities);
 	writeOutputFile(outputFile, result);

	return 0;
}
