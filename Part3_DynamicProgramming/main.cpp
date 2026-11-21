#include "WeightedInterval.h"
#include "DiscreteKnapsack.h"
#include "MaximumRemovals.h"

int main() {
    for (const string& filename : WEIGHTEDINTERVALFILES) {
        vector<IntervalDelivery> intervalDeliveries = readIntervalDeliveriesFromFile(filename);
        vector<IntervalDelivery> sortedIntervalDeliveries = sortByFinishTime(intervalDeliveries);
        IntervalDelivery dp = weightedIntervalScheduling(sortedIntervalDeliveries);

        cout << "Optimal schedule for " << filename << " is: " << endl <<
            dp.id << endl << "Earning: " << dp.profit << " profit" << endl << endl;
    }

    for (int i = 0; i < DISCRETEKNAPSACKFILES.size(); i ++) {
        vector<FuelDelivery> fuelDeliveries = readFuelDeliveriesFromFile(DISCRETEKNAPSACKFILES[i]);
        int b;
        cout << "Enter fuel budget (suggested " << DISCRETEKNAPSACKCAPACITIES[i] << "): ";
        cin >> b;
        FuelDelivery opt = discreteKnapsack(fuelDeliveries, b);

        cout << "Optimum selection for " << DISCRETEKNAPSACKFILES[i] << " is:" << endl
            << "Delivery IDs: " << opt.id << endl << "Costing " << opt.fuelCost << " fuel" << endl
            << "Earning " << opt.profit << " profit. " << endl << endl; 
    }

    for (int i = 0; i < MAXIMUMREMOVALFILES.size(); i++){
        Record record = readRecordFromFile(MAXIMUMREMOVALFILES[i]);
        Result res = findMaximumRemovals(record);
        cout << "Source: " << record.source << endl;
        cout << "Pattern: " << record.pattern << endl;
        if (!res.valid) {
            cout << "Pattern is not a substring, no removals made." << endl << endl;
            continue;
        }
        cout << "Maximum removals for " << MAXIMUMREMOVALFILES[i] << " is: " << res.removals << endl;
        cout << "Removal positions: ";
        for (int i = 0; i < res.removalPositions.size(); i++){
            cout << res.removalPositions[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < res.removalPositions.size(); i++){
            record.source[res.removalPositions[i]] = '_';
        }
        cout << "Resulting source string: " << record.source << endl;
        cout << endl;
    }
}