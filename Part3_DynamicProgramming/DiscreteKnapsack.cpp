#include "DiscreteKnapsack.h"

FuelDelivery discreteKnapsack(const vector<FuelDelivery>& deliveries, int weight){
    vector<vector<FuelDelivery> > dp(deliveries.size() + 1, vector<FuelDelivery>(weight + 1));

    for (int i = 1; i <= deliveries.size(); ++i) {
        for (int w = 1; w <= weight; ++w) {
            if(deliveries[i-1].fuelCost <= w){
                dp[i][w] = 
                    dp[i-1][w].profit > (dp[i-1][w-deliveries[i-1].fuelCost].profit + deliveries[i-1].profit) ? 
                    dp[i-1][w] : dp[i-1][w-deliveries[i-1].fuelCost] + deliveries[i-1];
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[deliveries.size()][weight];
}

