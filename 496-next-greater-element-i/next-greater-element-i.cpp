class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack <int> s;
        vector<int> ans(nums1.size(), -1);
        for(int i=0; i<nums2.size(); i++)
        {
            while(!s.empty() && s.top() <= nums2[i]) {
                int element = s.top();
                s.pop();

                for(int j = 0; j < nums1.size(); j++) 
                {
                    if(nums1[j] == element) 
                    {
                        ans[j] = nums2[i];
                        break;
                    }
                }
            }

            s.push(nums2[i]);
        }
        return ans;
    }
};
