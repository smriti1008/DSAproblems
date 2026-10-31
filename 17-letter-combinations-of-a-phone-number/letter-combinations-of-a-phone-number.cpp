class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty())
        {
            return ans;
        }
        vector<string> mapping={
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        string temp = "";
        solve(digits, 0, temp, ans, mapping);
        return ans;
    }
private:
    void solve(string &digits, int ind, string &temp, vector<string>&ans, vector<string>&mapping)
    {
        if(ind==digits.size()){
            ans.push_back(temp);
            return;
        }
        int digit = digits[ind]-'0';
        string letters = mapping[digit];
        for(char ch: letters){
            temp.push_back(ch);
            solve(digits, ind+1, temp, ans, mapping);
            temp.pop_back();
        }
    }
};