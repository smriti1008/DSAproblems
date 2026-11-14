class Solution {
public:
    bool isVowel(char c)
    {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxVowels(string s, int k) {
        int currentVowel=0, maxVowel=0;
        for(int i = 0; i<k; i++){
            if(isVowel(s[i]))
            {
                currentVowel++;
            }
        }
        maxVowel = currentVowel;

        for(int i = k; i<s.length(); i++)
        {
            if(isVowel(s[i]))
            {
                currentVowel++;
            }
            if(isVowel(s[i-k]))
            {
                currentVowel--;
            }
            maxVowel = max(maxVowel, currentVowel);
        }
        return maxVowel;

    }
};