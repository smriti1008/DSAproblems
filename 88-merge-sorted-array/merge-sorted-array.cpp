class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<int> nums3(m+n);

        for(int i=0; i<m; i++)
        {
            nums3[i]=nums1[i];
        }
        for(int i=0; i<n; i++)
        {
            nums3[m+i]=nums2[i];
        }

        sort(nums3.begin(), nums3.end());

        for(int i=0; i<m+n; i++)
        nums1[i]=nums3[i];
    }
};