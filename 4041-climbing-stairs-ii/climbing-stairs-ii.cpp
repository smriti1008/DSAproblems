#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int climbStairs(int n, std::vector<int>& costs) {
        std::vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;
        
        for (int j = 1; j <= n; ++j) {
            for (int i = std::max(0, j - 3); i < j; ++i) {
                if (dp[i] != LLONG_MAX) {
                    long long jump_cost = costs[j - 1] + (long long)(j - i) * (j - i);
                    dp[j] = std::min(dp[j], dp[i] + jump_cost);
                }
            }
        }
        
        return dp[n];
    }
};