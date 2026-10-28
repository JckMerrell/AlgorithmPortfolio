#pragma once
#include "fileInput2.h"

using namespace std;

int deliveryTimeSelection(vector<int>& estimates, int target);
int deliveryTimeSelection(vector<int>& estimates, int left, int right, int target);
int partition(vector<int>& arr, int left, int right, int pivotValue);
int findGroupMedian(vector<int>& estimates, int left, int groupSize);