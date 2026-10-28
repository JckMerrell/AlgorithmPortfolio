#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const vector<string> CLOSESTPAIRFILES {
    "ClosestPair1.txt",
    "ClosestPair2.txt",
    "ClosestPair3.txt",
    "ClosestPair4.txt",
    "ClosestPair5.txt"
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