#include "medianOfMedians.h"

//Main Access
int deliveryTimeSelection(vector<int>& estimates, int target){
    return deliveryTimeSelection(estimates, 0, estimates.size()-1, target);
}

int deliveryTimeSelection(vector<int>& estimates, int left, int right, int target){
    int n = right - left + 1;

    // Base case: When the array is small (n <=5), sort and return kth element.
    if (n <= 5) {
        sort(estimates.begin() + left, estimates.begin() + right + 1);
        return estimates[left + target];
    }

    //Breaks the array into groups of 5, finds the medians of each
    vector<int> medians;
    for (int i = left; i <= right; i += 5) {
        int groupSize = min(5, right - i + 1);
        medians.push_back(findGroupMedian(estimates, i, groupSize));
    }

    //Recursively finds the median of the medians; our target is the midpoint of the array
    int pivotValue = deliveryTimeSelection(medians, 0, medians.size() - 1, medians.size()/2);

    int pivotIndex = partition(estimates, left, right, pivotValue);

    int relativePivotIdx = pivotIndex - left;

    if (relativePivotIdx == target) {
        return estimates[pivotIndex];
    } else if (target < relativePivotIdx) {
        return deliveryTimeSelection(estimates, left, pivotIndex - 1, target);
    } else {
        return deliveryTimeSelection(estimates, pivotIndex + 1, right, target - relativePivotIdx - 1);
    }
}

//Partitions the array such that all elements <= the pivot are on the left side, and all elements
// > the pivot are on the right side. Returns the location of the pivot.
int partition(vector<int>& arr, int left, int right, int pivotValue) {

    //Forces the pivot value to the right
    for (int i = left; i < right; ++i) {
        if (arr[i] == pivotValue) {
            swap(arr[i], arr[right]);
            break;
        }
    }

    //Shifts all elements smaller than the pivot to the left of it, and all elements greater to the right of it
    int pivot = arr[right];
    int i = left;
    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    //returns the pivot location
    return i;
}

//Standard sort on small group (n <=5), returns median
int findGroupMedian(vector<int>& estimates, int left, int groupSize) {
    sort(estimates.begin() + left, estimates.begin() + left + groupSize);
    return estimates[left + groupSize / 2];
}