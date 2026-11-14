class Solution {
public:
    int maximumLengthSubstring(string s) {
        int len = 0;
        unordered_map<char, int>freq;
        int start = 0, end = 0;
        for(int end = 0; end<s.length(); end++)
        {
            freq[s[end]]++;
            while(freq[s[end]]>2)
            {
                freq[s[start]]--;
                start++;
            }
            len = max(len, end-start+1);
        }
        return len;
    }
};