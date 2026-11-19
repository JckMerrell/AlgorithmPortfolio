#include "WeightedInterval.h"


int main() {
    for (const string& filename : WEIGHTEDINTERVALFILES) {
        vector<Delivery> deliveries = readLocationsFromFile(filename);
        vector<Delivery> sortedDeliveries = sortByFinishTime(deliveries);
        vector<int> dp = weightedIntervalScheduling(sortedDeliveries);

        cout << "Maximum profit for " << filename << ": " << dp.back() << endl;
    }
}