class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oddCount = 0, left = 0;
        int subarrayCount= 0;
        int total = 0;
        for(int right = 0; right<nums.size(); right++)
        {
            if(nums[right]%2==1 )
            {
                oddCount++;
                subarrayCount = 0;
            }
            while(oddCount == k)
            {
                if(nums[left]%2==1){
                    oddCount--;
                }
                left++;
                subarrayCount++;
            }
            total+=subarrayCount;
        }
        return total;
    }
};