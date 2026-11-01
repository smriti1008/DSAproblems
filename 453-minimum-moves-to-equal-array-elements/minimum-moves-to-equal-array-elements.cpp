class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int mn = nums[0];
        for(int i = 0; i<n; i++)
        {
            if(nums[i]<mn)
            {
                mn = nums[i];
            }
        }
        for(int i = 0; i<n ; i++)
        {
            count += nums[i]-mn;
        }
        return count;
    }
};