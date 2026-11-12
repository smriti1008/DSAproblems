class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        int start  = 0;
        long long count = 0;
        for(int end = 0; end < nums.size(); end++)
        {
            sum+=nums[end];
            long long score = sum*(end-start+1);
            while(sum * (end - start + 1)>=k && start<=end)
            {
                sum-=nums[start];
                start++;
            }
            count += (end-start+1);
        }
        return count;
    }
};