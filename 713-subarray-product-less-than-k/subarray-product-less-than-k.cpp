class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int count = 0;
        long long product = 1;
        for(int right = 0; right<n; right++)
        {
            product*=nums[right];
            while(left<=right && product>=k)
            {
                product/=nums[left];
                left ++;
            }
            count += right - left + 1;
        }
        return count;
    }
};