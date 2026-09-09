class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> s;
        vector<int> ans(temp.size(), 0);
        for(int i=0; i<temp.size();i++)
        {
            while(s.size()>0 && temp[s.top()]<temp[i])
            {
                int index = s.top();
                s.pop();
                ans[index] = i-index;
            }
            s.push(i);
        }
        return ans;
    }
};