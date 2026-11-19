#pragma once

#include "fileInput3.h"

using namespace std;

vector<Delivery> sortByFinishTime(const vector<Delivery>& deliveries);
int findLastNonConflicting(const vector<Delivery>& deliveries, int index);
vector<int> computePreviousIntervals(const vector<Delivery>& deliveries);
vector<int> weightedIntervalScheduling(const vector<Delivery>& deliveries);
