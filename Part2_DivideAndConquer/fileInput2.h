#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

const vector<string> CLOSESTPAIRFILES {
    "TestCases/ClosestPair1.txt",
    "TestCases/ClosestPair2.txt",
    "TestCases/ClosestPair3.txt",
    "TestCases/ClosestPair4.txt",
    "TestCases/ClosestPair5.txt"
};

const vector<string> COUNTINVERSIONSFILES {
    "TestCases/CountInversions1.txt",
    "TestCases/CountInversions2.txt",
    "TestCases/CountInversions3.txt",
    "TestCases/CountInversions4.txt",
    "TestCases/CountInversions5.txt"
};

const vector<string> MEDOFMEDIANSFILES{
    "TestCases/MedOfMedians1.txt",
    "TestCases/MedOfMedians2.txt",
    "TestCases/MedOfMedians3.txt",
    "TestCases/MedOfMedians4.txt",
    "TestCases/MedOfMedians5.txt",
    "TestCases/MedOfMedians6.txt",
    "TestCases/MedOfMedians7.txt",
    "TestCases/MedOfMedians8.txt"
};

const vector<int> MEDIANOFMEDIANSTARGETS{
    5,
    2,
    9,
    4,
    1,
    5,
    7,
    12
};

struct Location{
    string id;
    int x;
    int y;
};

inline double squareDistance(Location a, Location b){
    return ((b.x - a.x)*(b.x - a.x)) + ((b.y - a.y)*(b.y - a.y));
}

inline double dist(Location a, Location b) {
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y));
}

inline vector<Location> readLocationsFromFile(const string& filename) {
    ifstream inputFile(filename);
    vector<Location> locations;

    if (!inputFile) {
        throw runtime_error("Could not open file: " + filename);
    }

    Location location;

    while (inputFile >> location.id >> location.x >> location.y) {
        locations.push_back(location);
    }

    return locations;
}

inline void readIDSFromFile(const string& filename, vector<Location>& planned, vector<Location>& actual){
    ifstream inputFile(filename);

    if (!inputFile) {
        throw runtime_error("Could not open file: " + filename);
    }

    Location location;
    string line;
    getline(inputFile, line, '\n');
    stringstream s1(line);
    while (s1 >> location.id) {
        planned.push_back(location);
    }
    getline(inputFile, line, '\n');
    stringstream s2(line);
    while (s2 >> location.id) {
        actual.push_back(location);
    }
}

inline vector<int> readTimeEstaimatesFromFile(const string& filename){
    ifstream inputFile(filename);
    vector<int> times;

    if (!inputFile) {
        throw runtime_error("Could not open file: " + filename);
    }
    int temp;
    while(inputFile >> temp){
        times.push_back(temp);
    }
    return times;
}

inline vector<Location> sortLocationsByX(const vector<Location>& locations) {
    vector<Location> sortedLocations = locations;
    sort(sortedLocations.begin(), sortedLocations.end(), [](const Location& a, const Location& b) {
        return a.x < b.x;
    });
    return sortedLocations;
}

inline vector<Location> sortLocationsByY(const vector<Location>& locations) {
    vector<Location> sortedLocations = locations;
    sort(sortedLocations.begin(), sortedLocations.end(), [](const Location& a, const Location& b) {
        return a.y < b.y;
    });
    return sortedLocations;
}