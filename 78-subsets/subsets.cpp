class Solution {
public:
    void solve(vector<int>& nums, int index, vector<vector<int>>&ans, vector<int>& temp) {

        if(index==nums.size()){
        ans.push_back(temp);
        return;
        }

        solve(nums, index+1, ans, temp);
        temp.push_back(nums[index]);
        solve(nums, index+1, ans, temp);
        temp.pop_back();
        
    }

    vector<vector<int>> subsets(vector<int>&nums)
    {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums, 0, ans, temp);
        return ans;
    }
};