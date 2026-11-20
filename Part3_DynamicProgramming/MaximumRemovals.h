#pragma once
#include "fileInput3.h"

struct Result{
    int removals;
    vector<int> removalPositions;
};

Result findMaximumRemovals(const Record& record);