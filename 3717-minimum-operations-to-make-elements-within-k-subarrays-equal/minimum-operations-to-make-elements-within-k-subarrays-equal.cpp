#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    struct WindowTracker {
        multiset<long long> low, high;
        long long sum_low = 0, sum_high = 0;

        void balance() {
            while (low.size() > high.size() + 1) {
                auto it = prev(low.end());
                sum_low -= *it;
                sum_high += *it;
                high.insert(*it);
                low.erase(it);
            }
            while (low.size() < high.size()) {
                auto it = high.begin();
                sum_high -= *it;
                sum_low += *it;
                low.insert(*it);
                high.erase(it);
            }
        }

        void add(long long val) {
            if (low.empty() || val <= *prev(low.end())) {
                low.insert(val);
                sum_low += val;
            } else {
                high.insert(val);
                sum_high += val;
            }
            balance();
        }

        void remove(long long val) {
            auto it_low = low.find(val);
            if (it_low != low.end()) {
                sum_low -= val;
                low.erase(it_low);
            } else {
                auto it_high = high.find(val);
                if (it_high != high.end()) {
                    sum_high -= val;
                    high.erase(it_high);
                }
            }
            balance();
        }

        long long get_cost() const {
            long long median = *prev(low.end());
            long long left_cost = (long long)low.size() * median - sum_low;
            long long right_cost = sum_high - (long long)high.size() * median;
            return left_cost + right_cost;
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        
        vector<long long> cost(n - x + 1, 0);
        WindowTracker tracker;

        for (int i = 0; i < n; i++) {
            tracker.add(nums[i]);
            if (i >= x) {
                tracker.remove(nums[i - x]);
            }
            if (i >= x - 1) {
                cost[i - x + 1] = tracker.get_cost();
            }
        }

        const long long INF = 1e18;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = j * x; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];
                long long current_window_cost = cost[i - x];
                if (dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(dp[j][i], dp[j - 1][i - x] + current_window_cost);
                }
            }
        }

        return dp[k][n];
    }
};