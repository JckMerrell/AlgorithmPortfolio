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
	"test5A_mixed_order.txt",
    "test5B_mixed_order.txt",
    "test5C_mixed_order.txt",
    "test6A_partial_overlap.txt",
    "test6B_partial_overlap.txt",
    "test6C_partial_overlap.txt",
    "test7_custom.txt"
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

