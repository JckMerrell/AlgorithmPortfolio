#include "WeightedInterval.h"
#include "DiscreteKnapsack.h"

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

}