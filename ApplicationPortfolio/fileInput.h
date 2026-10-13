#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const vector<string> TESTFILES = {
	"test1_no_deliveries.txt",
	"test2_one_delivery.txt",
	"test3_three_chain.txt",
	"test4_overlapping.txt",
	"test5_mixed_order.txt",
    "test6_partial_overlap.txt",
    "test7_long_chain.txt",
    "test8_many_overlaps.txt",
    "test9_mixed_intervals.txt",
    "test10_duplicate_endpoints.txt"
};

struct Delivery {
    std::string id;
    int startTime;
    int endTime;
};

inline vector<Delivery> sortDeliveriesByEndTime(const vector<Delivery>& deliveries) {
    vector<Delivery> sortedDeliveries = deliveries;
    sort(sortedDeliveries.begin(), sortedDeliveries.end(), [](const Delivery& a, const Delivery& b) {
        return a.endTime < b.endTime;
    });
    return sortedDeliveries;
}

inline vector<Delivery> sortDeliveriesByStartTime(const vector<Delivery>& deliveries) {
	vector<Delivery> sortedDeliveries = deliveries;
	sort(sortedDeliveries.begin(), sortedDeliveries.end(), [](const Delivery& a, const Delivery& b) {
		return a.startTime < b.startTime;
		});
	return sortedDeliveries;
}

inline vector<Delivery> readEventsFromFile(const string& filename) {
    ifstream inputFile(filename);
    vector<Delivery> deliveries;

    if (!inputFile) {
        throw runtime_error("Could not open file: " + filename);
    }

    Delivery delivery;

    while (inputFile >> delivery.id >> delivery.startTime >> delivery.endTime) {
        deliveries.push_back(delivery);
    }

    return deliveries;
}

