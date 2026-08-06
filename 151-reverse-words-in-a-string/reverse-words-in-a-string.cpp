class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n=s.size();
        int i=0;
        while(i<n)
        {
            while(s[i]==' '&& i<n)
            {
                i++;
            }
            string word="";

            while(i<n && s[i]!=' ')
            {
                word+=s[i];
                i++;
            }

            if(!word.empty())
            {
                words.push_back(word);
            }
        }

        reverse(words.begin(), words.end());

        string ans="";

        for(i=0; i<words.size(); i++)
        {
            ans+=words[i];
            if(i!=words.size()-1)
            ans+=" ";
        }
        return ans;

    }
};