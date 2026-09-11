class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0 ;
        int i = 0;
        while(i<chars.size())
        {
            char ch = chars[i];
            int count = 0;
            while(i<chars.size() && chars[i]==ch)
            {
                count++;
                i++;
                
            }
            chars[ans]=ch;
            ans++;

            if(count>1)
            {
                string num = to_string(count);
                for(char c : num)
                {
                    chars[ans]=c;
                    ans++;
                }
            }
        }
        return ans;
    }
};
