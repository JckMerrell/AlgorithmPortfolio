#include "closestDelivery.h"
#include "countInversions.h"
#include "medianOfMedians.h"

int main(){
    cout << "======Testing: Closest Pairs=======" << endl;
    for (int i = 0; i < CLOSESTPAIRFILES.size(); i++)
    {
        vector<Location> testCase = readLocationsFromFile(CLOSESTPAIRFILES[i]);
        cout << "Test case: " << i+1 << endl;
        pair<Location, Location> closestPair = closestPairOfLocations(testCase);
        cout << "The closest pair is locations " << closestPair.first.id << " and " << closestPair.second.id 
        << " which have distance " << squareDistance(closestPair.first, closestPair.second) << endl;
        cout << endl;
    }
    cout << "======Testing: Counting Inversions=======" << endl;
    for (int i = 0; i < COUNTINVERSIONSFILES.size(); i++)
    {
        vector<Location> testPlanned, testActual;
        readIDSFromFile(COUNTINVERSIONSFILES[i], testPlanned, testActual);
        cout << "Test case: " << i+1 << endl;
        long long inversions = countInversions(testPlanned, testActual);
        cout << "The actual route had " << inversions << " inversions from the planned route." << endl;
        cout << endl;
    }
    cout << "======Testing: Median of Medians Selection=======" << endl;
    for (int i = 0; i < MEDOFMEDIANSFILES.size(); i++)
    {
        vector<int> times = readTimeEstaimatesFromFile(MEDOFMEDIANSFILES[i]);
        cout << "Test case: " << i+1 << endl;
        int result = deliveryTimeSelection(times, MEDIANOFMEDIANSTARGETS[i] - 1);
        cout << "The " << MEDIANOFMEDIANSTARGETS[i] << "th position has value: " << result << endl;
        cout << endl;
    }
    
}