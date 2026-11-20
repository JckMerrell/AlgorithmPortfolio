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

const vector<string> DISCRETEKNAPSACKFILES{
    "TestCases/DiscreteKnapsack1Empty.txt",
    "TestCases/DiscreteKnapsack2Simple.txt",
    "TestCases/DiscreteKnapsack3LargeAndSmall.txt",
    "TestCases/DiscreteKnapsack4Ties.txt",
    "TestCases/DiscreteKnapsack5Repetition.txt"
};

const vector<int> DISCRETEKNAPSACKCAPACITIES{
    50,
    18,
    10,
    10,
    6
};

struct IntervalDelivery{
    string id;
    int start;
    int finish;
    int profit;
    IntervalDelivery(){
        id = "";
        start = 0;
        finish = 0;
        profit = 0;
    }

    IntervalDelivery operator+(const IntervalDelivery other){
        IntervalDelivery ret;
        ret.id = this->id.empty() ? other.id : this->id + (", " + other.id);
        ret.profit = this->profit + other.profit;
        return ret;
    }
};

struct FuelDelivery{
    string id;
    int fuelCost;
    int profit;

    FuelDelivery(){
        id = "";
        fuelCost = 0;
        profit = 0;
    }

    FuelDelivery operator+(const FuelDelivery other){
        FuelDelivery ret;
        ret.id = this->id.empty() ? other.id : this->id + (", " + other.id);
        ret.fuelCost = this->fuelCost + other.fuelCost;
        ret.profit = this->profit + other.profit;
        return ret;
    }
};

inline vector<IntervalDelivery> readIntervalDeliveriesFromFile(const string& filename) {
    ifstream inputFile(filename);
    vector<IntervalDelivery> deliveries;

    if (!inputFile) {
        throw runtime_error("Could not open file: " + filename);
    }

    IntervalDelivery delivery;

    while (inputFile >> delivery.id >> delivery.start >> delivery.finish >> delivery.profit) {
        deliveries.push_back(delivery);
    }

    return deliveries;
}

inline vector<FuelDelivery> readFuelDeliveriesFromFile(const string& filename) {
    ifstream inputFile(filename);
    vector<FuelDelivery> deliveries;

    if (!inputFile) {
        throw runtime_error("Could not open file: " + filename);
    }

    FuelDelivery delivery;

    while (inputFile >> delivery.id >> delivery.fuelCost >> delivery.profit) {
        deliveries.push_back(delivery);
    }

    return deliveries;
}