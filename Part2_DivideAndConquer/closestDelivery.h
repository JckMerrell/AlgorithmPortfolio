#pragma once

#include "fileInput2.h"
#include <utility>
using namespace std;

pair<Location, Location> closestPairOfLocations(
    const vector<Location>& locationsX,
    const vector<Location>& locationsY,
    int start,
    int end
);

pair<Location, Location> closestPairOfLocations(
    const vector<Location>& locations
);
