#pragma once

#include "fileInput3.h"

using namespace std;

vector<IntervalDelivery> sortByFinishTime(const vector<IntervalDelivery>& deliveries);
int findLastNonConflicting(const vector<IntervalDelivery>& deliveries, int index);
vector<int> computePreviousIntervals(const vector<IntervalDelivery>& deliveries);
IntervalDelivery weightedIntervalScheduling(const vector<IntervalDelivery>& deliveries);
