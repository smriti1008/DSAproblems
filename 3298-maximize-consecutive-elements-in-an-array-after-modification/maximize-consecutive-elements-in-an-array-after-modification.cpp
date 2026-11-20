class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(1000002, 0);
        int max_len = 0;
        
        for (int x : nums) {
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;
            
            max_len = max({max_len, dp[x], dp[x + 1]});
        }
        
        return max_len;
    }
};