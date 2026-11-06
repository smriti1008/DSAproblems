class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a = "";
        string b = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i]!= '#')
            {
                a.push_back(s[i]);
            }
            else if(!a.empty())
            {
                a.pop_back();
            }
        }
        for(int i = 0; i < t.size(); i++)
        {
            if(t[i]!='#')
            {
                b.push_back(t[i]);
            }
            else if(!b.empty())
            {
                b.pop_back();
            }
        }
        return a==b;
    }
};