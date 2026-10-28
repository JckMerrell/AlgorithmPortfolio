#pragma once
#include "fileInput2.h"
using namespace std;

long long countInversions(vector<Location> planned, vector<Location> actual);
vector<int> convertActualToRanks(vector<Location> planned, vector<Location> actual);
long long countInversionsHelper(vector<int>& ranks, int left, int right);
long long countAndMerge(vector<int>& ranks, int left, int mid, int right);