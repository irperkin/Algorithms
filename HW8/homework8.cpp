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

vector<pair<int, int> > weightedActivitySelector(vector<Activity> &activities) {
	int numActivities = activities.size();
	vector<pair<int, int> > weightedActivities(numActivities);

	if(numActivities == 1) {
		weightedActivities.push_back(make_pair(activities[0].id, activities[0].value));
		return weightedActivities;
	}

	sort(activities.begin(), activities.end(), finishTimeSort);

	weightedActivities[0] = make_pair(activities[0].id, activities[0].value);
	int j;
	pair<int, int> x, y;
	for(int i = 1; i < numActivities; i++) {
		x = make_pair(activities[i].id, activities[i].value);
		for(j = i - 1; j >= 0 && activities[i].startTime <= activities[j].endTime; j--) { }
		y = make_pair(0, 0);
		if(j != -1) {
			y = make_pair(activities[j].id, activities[j].value);
		}
		weightedActivities[i] = make_pair( ,max(x.second + y.second, weightedActivities[i - 1].second));
	}

	return weightedActivities;
}

int weightedActivity(int n, vector<activity> &a) {
    if(n == 1) {
        return a[0].v;
    }
    vector<int> dp(n);
    dp[0] = a[0].v;
    int x, y, i, j;
    for(i=1; i<n; i++) {
        x = a[i].v;
        j = i - 1;
        while(j>=0 && a[i].s<=a[j].e) {
            j--;
        }
        y = 0;
        if(j != -1) {
            y = a[j].v;
        }
        dp[i] = max(x + y, dp[i-1]);
    }
    return dp[n-1];
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
 	weightedActivitySelector(activities);

	return 0;
}
