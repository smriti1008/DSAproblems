class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int maxF = 0, minP = INT_MAX;
        for (auto& it : items) {
            maxF = max(maxF, it[0]);
            minP = min(minP, it[1]);
        }
        vector<int> freq(maxF + 1, 0), mult(maxF + 1, 0);
        for (auto& it : items) freq[it[0]]++;
        for (int d = 1; d <= maxF; d++) {
            for (int k = d; k <= maxF; k += d) mult[d] += freq[k];
        }
        vector<int> dp(budget + 1, 0);
        for (auto& it : items) {
            int val = mult[it[0]], p = it[1];
            for (int b = budget; b >= p; b--) {
                dp[b] = max(dp[b], dp[b - p] + val);
            }
        }
        int ans = 0;
        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[b] + (budget - b) / minP);
        }
        return ans;
    }
};