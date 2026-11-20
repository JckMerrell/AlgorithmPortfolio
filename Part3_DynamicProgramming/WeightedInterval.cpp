#include "WeightedInterval.h"
#include <algorithm>

vector<IntervalDelivery> sortByFinishTime(const vector<IntervalDelivery>& deliveries) {
    vector<IntervalDelivery> sortedDeliveries = deliveries;
    sort(sortedDeliveries.begin(), sortedDeliveries.end(), [](const IntervalDelivery& a, const IntervalDelivery& b) {
        return a.finish < b.finish;
    });
    return sortedDeliveries;
}

int findLastNonConflicting(const vector<IntervalDelivery>& deliveries, int index) {
    int low = 0;
    int high = index - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (deliveries[mid].finish <= deliveries[index].start) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

vector<int> computePreviousIntervals(const vector<IntervalDelivery>& deliveries) {
    int n = deliveries.size();
    vector<int> p(n, -1);
    for (int j = 0; j < n; ++j) {
        p[j] = findLastNonConflicting(deliveries, j);
    }
    return p;
}

IntervalDelivery weightedIntervalScheduling(const vector<IntervalDelivery>& deliveries) {
    int n = deliveries.size();
    if (n == 0) {
        return {};
    }

    vector<IntervalDelivery> dp(n);
    vector<int> p = computePreviousIntervals(deliveries);

    dp[0] = deliveries[0];

    for (int j = 1; j < n; ++j) {
        IntervalDelivery addedProfit = deliveries[j];
        if (p[j] != -1) {
            addedProfit = addedProfit +  dp[p[j]];
        }
        dp[j] = dp[j-1].profit > addedProfit.profit ? dp[j-1] : addedProfit; 
    }

    return dp.back();
}

