class Solution {
public:
     void upperToLower(string &s, int index){
        if(index==-1)
        return;

        if(s[index]>='A'&& s[index]<='Z')
        {
            s[index]=s[index]-'A'+'a';
        }
        upperToLower(s, index-1);
        
    }
    string toLowerCase(string s){

        upperToLower(s, s.length()-1);
        return s;

    }
};