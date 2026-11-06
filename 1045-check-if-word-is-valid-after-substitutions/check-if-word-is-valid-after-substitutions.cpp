class Solution {
public:
    bool isValid(string s) {
       string ans = "";
       for(int i = 0; i < s.length(); i++)
       {
        ans.push_back(s[i]);

        int n = ans.length();
        if(n>=3 && ans[n-3] == 'a' &&
        ans[n-2] == 'b' &&
        ans[n-1] == 'c')
        {
            ans.pop_back();
            ans.pop_back();
            ans.pop_back();
        }
       }
       return ans.empty();
    }
};