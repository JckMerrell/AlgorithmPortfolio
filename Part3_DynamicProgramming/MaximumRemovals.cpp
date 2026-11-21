#include "MaximumRemovals.h"
#include <climits>
#include <unordered_set>

/*Main Algorithm. Bottom Up dynamic programming approach using a 2d dp array.
 * Time complexity: O(mn) where m is the length of the source string and n is the length of the pattern string.
 * Space complexity: O(mn) for the dp array.
 * Recovery of the solution is done by backtracking through the dp array to find the positions of the characters that can be removed.
 * This takes O(m) time, where m is the length of the source string.
*/
Result findMaximumRemovals(const Record& record){
    int m = record.source.length();
    int n = record.pattern.length();

    Result ret;
    
    const unordered_set<int> target{record.targetIndicies.begin(), record.targetIndicies.end()};
    string source =  record.source;
    string pattern =  record.pattern;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MIN));
    dp[m][n] = 0;

    for (int i = m - 1; i >= 0; i--) {
      dp[i][n] = (target.count(i) > 0 ? 1 : 0) + dp[i + 1][n];
      for (int j = n - 1; j >= 0; j--) {
        const int pick = source[i] == pattern[j] ? dp[i + 1][j + 1] : INT_MIN;
        const int skip = (target.count(i) > 0 ? 1 : 0) + dp[i + 1][j];
        dp[i][j] = max(pick, skip);
      }
    }

    if (dp[0][0] < 0) {
        ret.removals = 0;
        ret.valid = false;
        return ret;
    }

    ret.removals = dp[0][0];

    int i = 0;
    int j = 0;
    while (i < m) {
        int skip = INT_MIN;

        if (dp[i + 1][j] != INT_MIN) {
            skip = (target.count(i) > 0 ? 1 : 0) + dp[i + 1][j];
        }

        if (skip == dp[i][j]) {
            // source[i] is not needed for the pattern.
            // Remove it if its original position is a target.
            if (target.count(i) > 0) {
                ret.removalPositions.push_back(i);
            }
        } else {
            // Skipping cannot produce the optimal answer, so source[i]
            // must be used to match pattern[j].
            j++;
        }

        i++;
    }

    return ret;
    
}