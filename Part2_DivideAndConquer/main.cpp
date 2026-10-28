#include "closestDelivery.h"

int main(){
    for (int i = 0; i < CLOSESTPAIRFILES.size(); i++)
    {
        vector<Location> testCase = readLocationsFromFile(CLOSESTPAIRFILES[i]);
        cout << "Test case: " << i+1 << endl;
        pair<Location, Location> closestPair = closestPairOfLocations(testCase);
        cout << "The closest pair is locations " << closestPair.first.id << " and " << closestPair.second.id 
        << " which have distance " << squareDistance(closestPair.first, closestPair.second) << endl;
        cout << endl;
    }
    
}