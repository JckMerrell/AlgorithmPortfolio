#pragma once
#include "fileInput.h"
#include <queue>

//This algorithm takes an input of deliveries and maximizes the number of deliveries 
//that can be completed by a single driver.
//Sorting the input takes O(n log n) time, and the greedy selection of deliveries takes O(n) time, 
//resulting in an overall time complexity of O(n log n).
inline void maximizeDeliveries(const vector<Delivery>& deliveries)
{
	vector<Delivery> sortedDeliveries = sortDeliveriesByEndTime(deliveries);
	vector<Delivery> selectedDeliveries;
	for (int i = 0; i < sortedDeliveries.size(); i++)
	{
		if (selectedDeliveries.empty() || sortedDeliveries[i].startTime >= selectedDeliveries.back().endTime)
		{
			selectedDeliveries.push_back(sortedDeliveries[i]);
		}
	}

	for (int i = 0; i < selectedDeliveries.size(); i++)
	{
		cout << "Delivery ID: " << selectedDeliveries[i].id << " Starts at: " << selectedDeliveries[i].startTime 
			<< " and ends at: " << selectedDeliveries[i].endTime << endl;
	}

	cout << "Total deliveries: " << selectedDeliveries.size() << endl << endl;
}

//Helper struct for keeping track of drivers
struct Driver {
	int id;
	int endTime;
	vector<Delivery> deliveries;

	//Moderately janky overload to allow the priority queue to sort drivers by their end times
	operator int() const {
		return endTime;
	}
};


//This algorithm takes an input of deliveries and minimizes the number of drivers needed to complete all deliveries.
//Sorting the input takes O(n log n) time, and the greedy assignment of deliveries to drivers takes O(n) time, 
//as assigning each delivery takes O(1) time and each delivery needs to be assigned. The overall running time is therefor O(n log n).
inline void minimizeDrivers(vector<Delivery>& deliveries)
{
	int numDrivers = 0;
	vector<Delivery> sortedDeliveries = sortDeliveriesByStartTime(deliveries);
	priority_queue<Driver, vector<Driver>, greater<Driver>> driverEndTimes; // Min-heap to track the end times of drivers
	for (int i = 0; i < sortedDeliveries.size(); i++)
	{
		if (driverEndTimes.empty() || sortedDeliveries[i].startTime < driverEndTimes.top()) {
			Driver newDriver;
			newDriver.id = ++numDrivers;
			newDriver.endTime = sortedDeliveries[i].endTime;
			newDriver.deliveries.push_back(sortedDeliveries[i]);
			driverEndTimes.push(newDriver);
		}
		else {
			Driver temp = driverEndTimes.top();
			driverEndTimes.pop();
			temp.deliveries.push_back(sortedDeliveries[i]);
			temp.endTime = sortedDeliveries[i].endTime;
			driverEndTimes.push(temp);
		}
	}


	// Output the results
	cout << "Minimum drivers needed: " << numDrivers << endl;
	while (!driverEndTimes.empty()) {
		Driver driver = driverEndTimes.top();
		driverEndTimes.pop();
		cout << "Driver # " << driver.id << ": ";
		for (const auto& delivery : driver.deliveries) {
			cout << delivery.id << " ";
		}
		cout << endl;
	}

	cout << endl;


}

inline void removeIncompatibleDeliveries(vector<Delivery>& deliveries)
{
	vector<Delivery> sortedDeliveries = sortDeliveriesByEndTime(deliveries);
	vector<Delivery> compatibleDeliveries;
	vector<Delivery> incompatibleDeliveries;
	for (int i = 0; i < sortedDeliveries.size(); i++)
	{
		if (compatibleDeliveries.empty() || sortedDeliveries[i].startTime >= compatibleDeliveries.back().endTime)
		{
			compatibleDeliveries.push_back(sortedDeliveries[i]);
		}
		else
		{
			incompatibleDeliveries.push_back(sortedDeliveries[i]);
		}
	}
	cout << "Minimum deliveries to remove: " << incompatibleDeliveries.size() << endl;
	cout << "Deliveries to remove: ";
	for (const auto delivery : incompatibleDeliveries)
	{
		cout << delivery.id << " ";
	}
	cout << endl << endl;
}

