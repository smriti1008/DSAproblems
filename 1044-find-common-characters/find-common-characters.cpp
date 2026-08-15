class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        for(char c ='a'; c<='z'; c++)
        {
        int mincount = 100;
        for(string word : words)
        {
            int count = 0;
        
        for(char x : word)
        {
            if(x==c)
            count++;
        }
        mincount = min(mincount, count);
        }
        for(int i=0; i<mincount; i++)
        {
            ans.push_back(string(1,c));
        }
        }
        return ans;
    }
};