class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int start=0,end=0,ans,mid;
        for(int i=0;i<n;i++)
        {
            start=max(start,weights[i]);
            end+=weights[i];
        }
        while(start<=end)
        {
            mid=start+(end-start)/2;
            int package=0, neededDays=1;
            for(int i=0;i<n;i++)
            {
                package+=weights[i];
                if(package>mid)
                {
                    neededDays++;
                    package=weights[i];
                }
            }
            if(neededDays<=days)
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
};