class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minSum = INT_MAX;
        for(int size = l; size<=r; size++)
        {
            int left = 0, sum = 0;
            for(int right = 0; right<nums.size(); right++)
            {
                sum+=nums[right];
                if(right-left+1>size)
                {
                    sum-=nums[left];
                    left++;
                }
                if(right-left+1 == size && sum>0)
                {
                    minSum = min(minSum, sum);
                }
            }
        }
        return minSum==INT_MAX ? -1 : minSum;
    }
};