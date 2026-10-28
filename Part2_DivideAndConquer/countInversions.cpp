#include "countInversions.h"
#include <unordered_map>

//Access handle
long long countInversions(vector<Location> planned, vector<Location> actual){
    vector<int> plannedOrderRanks = convertActualToRanks(planned, actual);
    if (plannedOrderRanks.empty()) {
        return 0;
    }
    return countInversionsHelper(plannedOrderRanks, 0, plannedOrderRanks.size()-1);
}
//Recursively divides the array into equal halves, then counts inversions as it
//Merges back up. 
long long countInversionsHelper(vector<int>& ranks, int left, int right){
    long long inversions = 0;
    //Base case when there is only 1 item in a half
    if (left < right){
        int mid = (left + right) /2;

        //Recursive left/right halving
        inversions += countInversionsHelper(ranks, left, mid);
        inversions += countInversionsHelper(ranks, mid + 1, right);

        //Merge and count step
        inversions += countAndMerge(ranks, left, mid, right);
    }
    return inversions;
}
//Function to merge two halves and count inversions. Results in sorted array.
//Runs in O(n) time
long long countAndMerge(vector<int>& ranks, int left, int mid, int right){

    int leftsize = mid - left + 1, rightsize = right - mid;
    vector<int> l(leftsize), r(rightsize);

    //building the two halves. O(n).
    for (int i = 0; i < leftsize; i++)
    {
        l[i] = ranks[i+left];
    }
    for (int i = 0; i < rightsize; i++)
    {
        r[i] = ranks[i + mid + 1];
    }

    long long inversions = 0;
    int i = 0, j = 0, k = left;

    //Merging the halves and counting inversions. O(n) again.
    while (i < leftsize && j < rightsize){
        if (l[i] <= r[j]){
            ranks[k++] = l[i++];
        }
        else {
            ranks[k++] = r[j++];
            inversions += (leftsize - i);
        }
    }

    while (i < leftsize){
        ranks[k++] = l[i++];
    }
    while (j < rightsize){
        ranks[k++] = r[j++];
    }
    return inversions;
}
//This function takes the two input vectors, builds a map keyed on the planned schedule,
//and builds the rank vector from actual based on that key map. 
//This runs in O(n) time. 
vector<int> convertActualToRanks(vector<Location> planned, vector<Location> actual){
    unordered_map<string, int> plannedRank;
    //This step is O(n), going through the array once.
    for (int i = 0; i < planned.size(); i++)
    {
        plannedRank[planned[i].id] = i + 1;
    }

    vector<int> ranks;
    //Since unordered_map::at is O(1), this step is O(n)
    for (Location& location : actual)
    {
        ranks.push_back(plannedRank.at(location.id));
    }
    return ranks;
}

