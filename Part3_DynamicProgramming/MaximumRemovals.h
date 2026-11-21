#pragma once
#include "fileInput3.h"

struct Result{
    int removals;
    vector<int> removalPositions;
    bool valid;

    Result(){
        removals = 0;
        valid = true;
    }
};

Result findMaximumRemovals(const Record& record);