class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
        {
            return false;
        }

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(char c : s1)
        {
            freq1[c-'a']++;
        }

        int end = s1.length();
        for(int i=0 ; i< end; i++)
        {
            freq2[s2[i]-'a']++;
        }
        if(freq1==freq2)
        {return true;
        }
        int start = 0;
        while(end<s2.length())
        {
            int i = end;
            freq2[s2[i]-'a']++;
            freq2[s2[start]-'a']--;
            if(freq1==freq2)
            {
                return true;
            }
            start++;
            end++;
        }
        return false;
    }
};