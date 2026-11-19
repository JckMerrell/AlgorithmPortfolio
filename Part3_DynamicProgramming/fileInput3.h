#pragma once
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

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