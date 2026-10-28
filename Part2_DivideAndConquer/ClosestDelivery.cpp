#include "closestDelivery.h"
#include <unordered_set>

//
pair<Location, Location> closestPairOfLocations(const vector<Location>& locationsX, const vector<Location>& locationsY, int start, int end){
    if (locationsX.size() < 2){
        throw invalid_argument("There must be at least 2 locations.");
    }
    //Brute force base case
    if (end - start <= 2) {
        pair<Location, Location> minPair = {locationsX[start], locationsX[start + 1]};
        double d = dist(minPair.first, minPair.second);

        for (int i = start; i <= end; i++) {
            for (int j = i + 1; j <= end; j++) {
                double currentDist = dist(locationsX[i], locationsX[j]);

                if (currentDist < d) {
                    d = currentDist;
                    minPair = {locationsX[i], locationsX[j]};
                }
            }
        }
        return minPair;
    }
    int mid = (start + end)/2;

    unordered_set<string> leftIDs;

    for (int i = start; i <= mid; i++) {
        leftIDs.insert(locationsX[i].id);
    }

    vector<Location> leftY;
    vector<Location> rightY;

    for (const Location& location : locationsY) {
        if (leftIDs.count(location.id)) {
            leftY.push_back(location);
        }
        else {
            rightY.push_back(location);
        }
    }

    pair<Location,Location> leftMin = closestPairOfLocations(locationsX, leftY, start, mid);
    double leftDist = dist(leftMin.first, leftMin.second);
    pair<Location,Location> rightMin = closestPairOfLocations(locationsX, rightY, mid+1, end);
    double rightDist = dist(rightMin.first, rightMin.second);

    pair<Location, Location> minPair;
    double d;
    if (leftDist < rightDist){
        d = leftDist;
        minPair = leftMin;
    }
    else{
        d = rightDist;
        minPair = rightMin;
    }

    vector<Location> midlineStrip;
    //Loop takes n time
    for (int i = 0; i < locationsY.size(); i++)
    {
        if (abs(locationsY[i].x - locationsX[mid].x) < d){
            midlineStrip.push_back(locationsY[i]);
        }
    }

    for (int i = 0; i < midlineStrip.size(); i++)
    {
        for (int j = i + 1; j < midlineStrip.size() &&
            (midlineStrip[j].y - midlineStrip[i].y < d); j++)
        {
            double tempd = dist(midlineStrip[i], midlineStrip[j]);
            if (tempd < d){
                d = tempd;
                minPair = {midlineStrip[i], midlineStrip[j]};
            }

        }
        
    }
    return minPair;

}

pair<Location, Location> closestPairOfLocations(const vector<Location>& locations){
    return closestPairOfLocations(sortLocationsByX(locations), sortLocationsByY(locations), 0, (locations.size()-1));
}