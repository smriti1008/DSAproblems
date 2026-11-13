class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        long long cost = 0;
        deque<int> dq; // Stores indices of `nums` in non-increasing order

        for (int i = nums.size() - 1, j = nums.size() - 1; i >= 0; --i) {
            int num = nums[i];
            
            // Maintain monotonic property by popping smaller elements and adding to cost
            while (!dq.empty() && nums[dq.back()] < num) {
                int l = dq.back();
                dq.pop_back();
                int r = dq.empty() ? j + 1 : dq.back();
                cost += static_cast<long long>(r - l) * (num - nums[l]);
            }
            dq.push_back(i);

            // Shrink the window from the right if the cost exceeds k
            while (cost > k) {
                cost -= nums[dq.front()] - nums[j];
                if (dq.front() == j) {
                    dq.pop_front();
                }
                --j;
            }

            // All valid subarrays starting at `i` and ending anywhere between `i` and `j`
            ans += (j - i + 1);
        }

        return ans;
    }
};