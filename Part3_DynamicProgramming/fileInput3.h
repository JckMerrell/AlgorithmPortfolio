#pragma once
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

const vector<string> WEIGHTEDINTERVALFILES{
    "TestCases/WeightedInterval1.txt",
    "TestCases/WeightedInterval2.txt",
    "TestCases/WeightedInterval3.txt",
    "TestCases/WeightedInterval4.txt",
    "TestCases/WeightedInterval5.txt"
};

struct Delivery{
    string id;
    int start;
    int finish;
    int profit;
};

inline vector<Delivery> readLocationsFromFile(const string& filename) {
    ifstream inputFile(filename);
    vector<Delivery> deliveries;

    if (!inputFile) {
        throw runtime_error("Could not open file: " + filename);
    }

    Delivery delivery;

    while (inputFile >> delivery.id >> delivery.start >> delivery.finish >> delivery.profit) {
        deliveries.push_back(delivery);
    }

    return deliveries;
}