class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int maxVal = INT_MIN;
        for(int i=0; i<n; i++)
        {
            int l=i;
            int r=i;

            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxVal)
                {
                    start = l;
                    maxVal = r-l+1;
                }
                l--, r++;
            }
            l = i, r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxVal)
                {
                    start = l;
                    maxVal = r-l+1;
                }
                l--, r++;
            }
        }
        return s.substr(start, maxVal);
    }
};