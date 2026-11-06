class Solution {
public:
    int minLength(string s) {
        string ans = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(!ans.empty() && ((ans.back()=='A' && s[i] == 'B') || 
            (ans.back()=='C' && s[i] == 'D')))
            {
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans.length();
    }
};