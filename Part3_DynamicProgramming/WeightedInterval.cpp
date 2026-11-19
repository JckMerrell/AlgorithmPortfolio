#include "WeightedInterval.h"
#include <algorithm>

vector<Delivery> sortByFinishTime(const vector<Delivery>& deliveries) {
    vector<Delivery> sortedDeliveries = deliveries;
    sort(sortedDeliveries.begin(), sortedDeliveries.end(), [](const Delivery& a, const Delivery& b) {
        return a.finish < b.finish;
    });
    return sortedDeliveries;
}

int findLastNonConflicting(const vector<Delivery>& deliveries, int index) {
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

vector<int> computePreviousIntervals(const vector<Delivery>& deliveries) {
    int n = deliveries.size();
    vector<int> p(n, -1);
    for (int j = 0; j < n; ++j) {
        p[j] = findLastNonConflicting(deliveries, j);
    }
    return p;
}

vector<int> weightedIntervalScheduling(const vector<Delivery>& deliveries) {
    int n = deliveries.size();
    if (n == 0) {
        return {};
    }

    vector<int> dp(n, 0);
    vector<int> p = computePreviousIntervals(deliveries);

    dp[0] = deliveries[0].profit;

    for (int j = 1; j < n; ++j) {
        int includeProfit = deliveries[j].profit;
        if (p[j] != -1) {
            includeProfit += dp[p[j]];
        }
        dp[j] = max(dp[j - 1], includeProfit);
    }

    return dp;
}

